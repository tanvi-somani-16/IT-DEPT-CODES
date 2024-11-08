#include <stdio.h>
#include <stdlib.h>

int FIFO(int pages[], int n, int capacity){
    int *s = (int *)malloc(capacity * sizeof(int));
    int page_fault = 0;
    int size = 0;
    int front = 0;

    // Initialize frames to -1
    for(int i = 0; i < capacity; i++) {
        s[i] = -1;
    }

    printf("\n--------- Frame In Memory ----------\n");
    for(int j = 0; j < n; j++) {
        int current_pg = pages[j];
        int found = 0;

        // Check if the page is already in the frame
        for(int k = 0; k < size; k++) {
            if(s[k] == current_pg) {
                found = 1;
                break;
            }
        }

        if (!found) {
            if (size < capacity) {
                s[size++] = current_pg; // Add page if space is available
            } else {
                s[front] = current_pg; // Replace page in FIFO order
                front = (front + 1) % capacity;
            }
            page_fault++;
        }

        // Print the current state of the frames
        printf("\nCurrent_Page:%d |", current_pg);
        for(int l = 0; l < capacity; l++) {
            if(s[l] != -1) {
                printf(" %d |", s[l]);
            } else {
                printf("   |");
            }
        }
        printf("%s", !found ? " | MISS" : " | HIT");
    }
    free(s);
    return page_fault;
}

int LRU(int pages[], int n, int capacity){
    int *s = (int *)malloc(capacity * sizeof(int));
    int page_fault = 0;
    int size = 0;
    int *last_used = (int *)malloc(capacity * sizeof(int));

    // Initialize frames and last used array
    for(int i = 0; i < capacity; i++) {
        s[i] = -1;
        last_used[i] = 0;
    }

    printf("\n--------- Frame In Memory ----------\n");
    for(int j = 0; j < n; j++) {
        int current_pg = pages[j];
        int found = 0;

        // Check if the page is already in the frame
        for(int k = 0; k < size; k++) {
            if(s[k] == current_pg) {
                found = 1;
                last_used[k] = j; // Update the last used time
                break;
            }
        }

        if (!found) {
            if (size < capacity) {
                s[size] = current_pg;
                last_used[size++] = j; // Add the page and update last used
            } else {
                // Find the Least Recently Used page to replace
                int lru_index = 0;
                for(int l = 1; l < size; l++) {
                    if(last_used[l] < last_used[lru_index]) {
                        lru_index = l;
                    }
                }
                s[lru_index] = current_pg;
                last_used[lru_index] = j;
            }
            page_fault++;
        }

        // Print the current state of the frames
        printf("\nCurrent_Page:%d |", current_pg);
        for(int l = 0; l < capacity; l++) {
            if(s[l] != -1) {
                printf(" %d |", s[l]);
            } else {
                printf("   |");
            }
        }
        printf("%s", !found ? " | MISS" : " | HIT");
    }
    free(s);
    free(last_used);
    return page_fault;
}

int Optimal(int pages[], int n, int capacity){
    int *s = (int *)malloc(capacity * sizeof(int));
    int page_fault = 0;
    int size = 0;

    // Initialize frames to -1
    for(int i = 0; i < capacity; i++) {
        s[i] = -1;
    }

    printf("\n--------- Frame In Memory ----------\n");
    for(int j = 0; j < n; j++) {
        int current_pg = pages[j];
        int found = 0;

        // Check if the page is already in the frame
        for(int k = 0; k < size; k++) {
            if(s[k] == current_pg) {
                found = 1;
                break;
            }
        }

        if (!found) {
            if (size < capacity) {
                s[size++] = current_pg; // Add page if space is available
            } else {
                // Find the page to replace (optimal strategy)
                int farthest_index = -1;
                int pg_to_replace = -1;

                for(int i = 0; i < capacity; i++) {
                    int k;
                    for(k = j + 1; k < n; k++) {
                        if(s[i] == pages[k]) {
                            if(k > farthest_index) {
                                farthest_index = k;
                                pg_to_replace = i;
                            }
                            break;
                        }
                    }
                    if(k == n) {
                        pg_to_replace = i;
                        break;
                    }
                }

                s[pg_to_replace] = current_pg; // Replace page with the farthest one
            }
            page_fault++;
        }

        // Print the current state of the frames
        printf("\nCurrent_Page:%d |", current_pg);
        for(int l = 0; l < capacity; l++) {
            if(s[l] != -1) {
                printf(" %d |", s[l]);
            } else {
                printf("   |");
            }
        }
        printf("%s", !found ? " | MISS" : " | HIT");
    }
    free(s);
    return page_fault;
}

void hit_ratio(int faults, int n){
    float ratio = (float)(n - faults) / n;
    printf("\nHit-Ratio: %.2f", ratio);
}

void miss_ratio(int faults, int n){
    float ratio = (float) faults / n;
    printf("\nMiss-Ratio: %.2f\n", ratio);
}

int main(){
    int pages[] = { 4, 7, 6, 1, 7, 6, 1, 2, 7, 2};
    int n = sizeof(pages)/sizeof(pages[0]);
    int capacity = 3;
    int opt = 0;  // Initialize opt to avoid undefined behavior

    while(opt != 4) {
        printf("\nChoose an algorithm:\n");
        printf("1. FIFO\n");
        printf("2. LRU\n");
        printf("3. Optimal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &opt);

        int faults = 0;
        switch(opt) {
            case 1: 
                faults = FIFO(pages, n, capacity);
                hit_ratio(faults, n);
                miss_ratio(faults, n);
                break;
            case 2: 
                faults = LRU(pages, n, capacity);
                hit_ratio(faults, n);
                miss_ratio(faults, n);
                break;
            case 3: 
                faults = Optimal(pages, n, capacity);
                hit_ratio(faults, n);
                miss_ratio(faults, n);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Enter a valid option.\n");
                break;
        }
    }
    return 0;
}
