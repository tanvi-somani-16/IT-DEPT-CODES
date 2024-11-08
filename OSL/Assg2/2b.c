#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of integers: \n");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the integers: \n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Forking a child process
    pid_t pid = fork();

    if(pid < 0) {
        printf("Fork failed\n");
        exit(1);
    }
    else if(pid == 0) {
        // Child process
        printf("Array in sorted order:\n");
        bubbleSort(arr, n);
        for(int i = 0; i < n; i++) {
            printf("%d\n", arr[i]);
        }
        printf("Child process\n");
        printf("Child process ID (PID: %d)\n", getpid());
        printf("Parent process ID (PID: %d)\n", getppid());

        // Convert array elements to strings for execve()
        char arr_str[n][10];  // Array to hold string representations of integers
        char *args[n + 2];    // Array of arguments for execve()

        args[0] = "./2b1";  // Path to the child executable
        for(int i = 0; i < n; i++) {
            sprintf(arr_str[i], "%d", arr[i]);  // Convert integer to string
            args[i + 1] = arr_str[i];           // Set as argument
        }
        args[n + 1] = NULL;  // End of arguments for execve()

        execve(args[0], args, NULL);  // Execute the child process
        perror("execve failed");  // If execve fails, print error
        exit(1);
    }
    else {
        // Parent process
        wait(NULL);  // Wait for child process to finish
        printf("Parent process\n");
        printf("Parent process ID (PID: %d)\n", getpid());
    }
    return 0;
}

