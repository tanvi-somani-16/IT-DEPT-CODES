#include <stdio.h>
#include <stdlib.h>

struct process {
    int max[10], allocated[10], need[10];
} p[10];

int n, m;

void input(int available[]) {
    for (int i = 0; i < n; i++) {
        printf("Enter the details of process P%d:\n", i);
        printf("Enter the number of allocated resources: ");
        for (int j = 0; j < m; j++) {
            scanf("%d", &p[i].allocated[j]);
        }
        printf("Enter the max resources: ");
        for (int j = 0; j < m; j++) {
            scanf("%d", &p[i].max[j]);
            p[i].need[j] = p[i].max[j] - p[i].allocated[j];
        }
    }
    printf("Enter the available resources: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &available[i]);
    }
}

void display(struct process p[]) {
    printf("\nPID\tALLOCATED\tMAX\tNEED\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t", i);
        for (int j = 0; j < m; j++)
            printf("%d ", p[i].allocated[j]);
        printf("\t\t");
        for (int j = 0; j < m; j++)
            printf("%d ", p[i].max[j]);
        printf("\t\t");
        for (int j = 0; j < m; j++)
            printf("%d ", p[i].need[j]);
        printf("\n");
    }
}


int safetyalgorithm(int available[], int safesequence[], struct process p[]) {
    int work[m]; // Work vector for tracking available resources
    for (int i = 0; i < m; i++) {
        work[i] = available[i]; // Initialize work with available resources
    }

    int finish[n]; // Track if process has finished
    for (int i = 0; i < n; i++) {
        finish[i] = 0; // Initialize all processes as unfinished
    }

    int safeCount = 0;  // Keep track of how many processes are completed

    while (safeCount < n) { 
        int progressMade = 0; 
        // Flag to track if any process progresses in this iteration, If no process can execute in an iteration, we should break out and declare the system unsafe.

        for (int i = 0; i < n; i++) { // Check each process
            if (finish[i] == 0) { // If the process is not finished
                int canExecute = 1; // Flag to check if the process can execute

                // Check if all required resources (need) are available
                for (int j = 0; j < m; j++) {
                    if (p[i].need[j] > work[j]) { // If any need is more than available work
                        canExecute = 0; // This process cannot execute
                        break;
                    }
                }

                if (canExecute) { // If the process can proceed
                    // Add the process's allocated resources back to work
                    for (int j = 0; j < m; j++) {
                        work[j] += p[i].allocated[j];
                    }

                    safesequence[safeCount++] = i; // Record the process in the safe sequence
                    finish[i] = 1; // Mark the process as finished
                    progressMade = 1; // At least one process made progress in this iteration
                    break; // Break the loop and try again to allocate resources
                }
            }
        }

        if (progressMade == 0) { // No process could execute, unsafe state
            return 0;
        }
    }

    // All processes finished, the system is in a safe state
    return 1;
}


int isSafeState(int available[], int safesequence[], struct process p[]) {
    return safetyalgorithm(available, safesequence, p);
}

void resourceRequest(int available[], int safesequence[], struct process p[]) {
    int processNum;
    printf("Enter the Process number for request: ");
    scanf("%d", &processNum);

    int request[m];
    printf("Enter the requested resources for Process P%d:\n", processNum);
    for (int i = 0; i < m; i++) {
        printf("Resource %d: ", i + 1);
        scanf("%d", &request[i]);
    }

    for (int i = 0; i < m; i++) {
        if (request[i] > p[processNum].need[i]) {
            printf("Error: Process has exceeded its maximum claim.\n");
            return;
        }
        if (request[i] > available[i]) {
            printf("Resources not available. Process must wait.\n");
            return;
        }
    }

    for (int i = 0; i < m; i++) {
        available[i] -= request[i];
        p[processNum].allocated[i] += request[i];
        p[processNum].need[i] -= request[i];
    }

    if (isSafeState(available, safesequence, p)) {
        printf("Resources allocated successfully. System remains in a safe state.\n");
    } else {
        printf("System not in a safe state after allocation. Rolling back.\n");
        for (int i = 0; i < m; i++) {
            available[i] += request[i];
            p[processNum].allocated[i] -= request[i];
            p[processNum].need[i] += request[i];
        }
    }
}

int main() {
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);

    int available[m], safesequence[n];
    input(available);
    display(p);

    int choice;
    do {
        printf("\nMenu:\n1. Check if the system is in a safe state\n2. Display safe sequence\n3. Request resources for a process\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (isSafeState(available, safesequence, p)) {
                    printf("System is in a safe state.\n");
                } else {
                    printf("System is not in a safe state.\n");
                }
                break;

            case 2:
                if (isSafeState(available, safesequence, p)) {
                    printf("Safe Sequence: ");
                    for (int i = 0; i < n; i++) {
                        printf("P%d ", safesequence[i]);
                        if (i < n - 1) printf("-> ");
                    }
                    printf("\n");
                }
                break;

            case 3:
                resourceRequest(available, safesequence, p);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
