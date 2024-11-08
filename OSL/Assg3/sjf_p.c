#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int at; // Arrival time
    int bt; // Burst time
    int rt; // Remaining time
    int ct; // Completion time
    int st; // Start time
} Process;

typedef struct {
    int process_id;
    int start_time;
    int end_time;
} GanttChartEntry;

void print_gantt_chart(GanttChartEntry gantt[], int count) {
    printf("\nGantt Chart:\n");
    for (int i = 0; i < count; i++) {
        printf("| P%d ", gantt[i].process_id);
    }
    printf("|\n");

    printf("%d", gantt[0].start_time);
    for (int i = 0; i < count; i++) {
        printf("    %d", gantt[i].end_time);
    }
    printf("\n");
}

void sjf(Process p[], int n) {
    int current_time = 0;
    int remaining_processes = n;
    int total_wt = 0, total_tat = 0;
    GanttChartEntry gantt[100];
    int gantt_count = 0;

    while (remaining_processes > 0) {
        int selected_process = -1;

        // Find the process with the shortest remaining time that has arrived
        for (int i = 0; i < n; i++) {
            if (p[i].at <= current_time && p[i].rt > 0) {
                if (selected_process == -1 || p[i].rt < p[selected_process].rt) {
                    selected_process = i;
                }
            }
        }

        // If a process is selected, simulate its execution
        if (selected_process != -1) {
            // If the process is executing for the first time, record its start time
            if (p[selected_process].rt == p[selected_process].bt) {
                p[selected_process].st = current_time;
            }

            // Record Gantt chart entry
            if (gantt_count == 0 || gantt[gantt_count - 1].process_id != p[selected_process].id) {
                gantt[gantt_count].process_id = p[selected_process].id;
                gantt[gantt_count].start_time = current_time;
                gantt[gantt_count].end_time = current_time + 1;
                gantt_count++;
            } else {
                gantt[gantt_count - 1].end_time = current_time + 1;
            }

            // Process executes for one time unit
            p[selected_process].rt--;

            // If process completed, update times
            if (p[selected_process].rt == 0) {
                remaining_processes--;
                p[selected_process].ct = current_time + 1;

                // Calculate waiting and turnaround time
                total_wt += p[selected_process].ct - p[selected_process].at - p[selected_process].bt;
                total_tat += p[selected_process].ct - p[selected_process].at;
            }
        }
        current_time++;
    }

    // Calculate and display average wait time and turnaround time
    float avg_wt = (float)total_wt / n;
    float avg_tat = (float)total_tat / n;
    printf("Average Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tat);

    print_gantt_chart(gantt, gantt_count);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter Arrival Time for Process %d: ", i + 1);
        scanf("%d", &p[i].at);
        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &p[i].bt);
        p[i].rt = p[i].bt; // Initialize remaining time
        p[i].ct = 0; // Initialize completion time
    }

    sjf(p, n);

    printf("\nSJF (PREEMPTIVE) SCHEDULING\n");
    printf("Process    Arrival Time    Burst Time    Start Time    Completion Time\n");
    for (int i = 0; i < n; i++) {
        printf("   %d            %d              %d              %d               %d\n",
               p[i].id, p[i].at, p[i].bt, p[i].st, p[i].ct);
    }

    return 0;
}

