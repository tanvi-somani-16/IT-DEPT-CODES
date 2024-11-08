#include<stdio.h>
#include<stdlib.h>

#define MAX 100	//maximun number of processes

typedef struct{
	int id;
	int bt;
	int at;
	int wt;
	int tat;
	int rt; //remaining time;
}Process;

//SJF NON-PREMPTIVE
void sjf(Process p[],int n){

	//SJF scheduling logic
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(p[j].bt>p[j+1].bt){
				Process temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	}
	
	//Finding waiting time and turn around time for each process
	int current_time=0;
	for(int i=0;i<n;i++){
		p[i].wt=current_time-p[i].at;
		if(p[i].wt<0){
			p[i].wt=0;
		}
		p[i].tat=p[i].wt+p[i].bt;
		current_time+=p[i].bt;
	}
}

void round_robin(Process p[],int n,int quantum){
	//Round Robin logic
	int remaining_processes=n;
	int current_time=0;
	
	while(remaining_processes>0){
		for(int i=0;i<n;i++){
			if(p[i].rt>0){
				if(p[i].rt<=quantum){
					current_time+=p[i].rt;
					p[i].rt=0;
				}
				else{
					current_time+=quantum;
					p[i].rt-=quantum;
				}
			
				//waiting time
				p[i].wt=current_time-p[i].at-p[i].bt;
		
				//turn around time
				if(p[i].rt==0){
					remaining_processes--;
					p[i].tat=current_time-p[i].at;
				}
			}
		}	
	}
}

void gantt_chart_sjf(Process p[],int n){
	printf("\n Gantt Chart\n");
	//printing process
	int current_time=0;
	
	for(int i=0;i<n;i++){
		if(current_time<p[i].at){
			current_time=p[i].at;
		}
		printf("| P%d",p[i].id);
		current_time+=p[i].bt;
	} 
	printf("|");
	printf("\n");
	
	current_time=0;
	for(int i=0;i<n;i++){
		if(current_time<p[i].at){
			current_time=p[i].at;
		}
		if (i == 0) {
        printf("%-4d", p[i].at); // Print the arrival time of the first process
    	}
		current_time+=p[i].bt;
		printf("%-4d",current_time);
	}
	printf("\n");
}

void gantt_chart_rr(Process p[], int n, int quantum) {
    int current_time = 0, remaining_processes = n;
    int remaining_time[n];
    
    // Initialize remaining burst times
    for (int i = 0; i < n; i++) remaining_time[i] = p[i].bt;

    // Print Gantt chart header
    printf("\nGantt Chart\n");
    printf("|");
    // Generate Gantt chart for Round Robin
    while (remaining_processes > 0) {
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
            	
                printf(" P%d |", p[i].id);

                // Calculate time slice for each process
                int time_slice = (remaining_time[i] > quantum) ? quantum : remaining_time[i];
                current_time += time_slice;
                remaining_time[i] -= time_slice;

                // If the process finishes in this slice, decrement remaining processes
                if (remaining_time[i] == 0) remaining_processes--;
            }
        }
    }
    printf("\n");

    // Print timeline below the Gantt chart
    current_time = 0;
    printf("%-2d", current_time);
    remaining_processes = n;

    // Reset remaining times for timeline calculation
    for (int i = 0; i < n; i++) remaining_time[i] = p[i].bt;
    
    while (remaining_processes > 0) {
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                int time_slice = (remaining_time[i] > quantum) ? quantum : remaining_time[i];
                current_time += time_slice;
                remaining_time[i] -= time_slice;
                printf("   %-2d", current_time);

                if (remaining_time[i] == 0) remaining_processes--;
            }
        }
    }
    printf("\n");
}


int main(){
	Process p[MAX];
	int i,j,n,quantum;
	
	int total_wt_sjf=0,total_tat_sjf=0;
	int total_wt_rr=0,total_tat_rr=0;
	
	printf("Enter the number of processes: ");
	scanf("%d",&n);
	printf("Enter burst time and arrival time for each process \n");
	
	for(i=0;i<n;i++){
		p[i].id=i+1;
		printf("P[%d] arrival time : ",i+1);
		scanf("%d",&p[i].at);
		printf("P[%d] burst time : ",i+1);
		scanf("%d",&p[i].bt);
		
		p[i].wt=p[i].tat=0;
		p[i].rt=p[i].bt;
	}
	int choice;
	printf("Enter choice : \n");
	printf("1. SJF(NON-PREMPTIVE)\n");
	printf("2. Round Robin \n");
	scanf("%d",&choice);
	
	switch(choice){
		case 1:
			sjf(p,n);
			printf("SJF (NON-PREMPTIVE) SCHEDULING\n");
			printf("Processes    Arrival Time    Burst Time    Waiting Time    Turn Around Time \n");
			for(int i=0;i<n;i++){
				total_wt_sjf+=p[i].wt;
				total_tat_sjf+=p[i].tat;
				printf("   %d            %d              %d              %d               %d\n",
               				p[i].id, p[i].at, p[i].bt, p[i].wt, p[i].tat);
			}
			
			float avg_wt=(float) total_wt_sjf/(float) n;
			float avg_tat=(float) total_tat_sjf/(float) n;
			
			
			printf("Average waiting time : %.2f \n",avg_wt);
			printf("Avergae turn around time : %.2f \n",avg_tat);
			
			gantt_chart_sjf(p,n);
			printf("\n");
			break;
			
		case 2:
			printf("Enter quantum : ");
			scanf("%d",&quantum);
			round_robin(p,n,quantum);
			printf("ROUND ROBIN SCHEDULING\n");
			printf("Processes    Arrival Time    Burst Time    Waiting Time    Turn Around Time \n");
			for(int i=0;i<n;i++){
				total_wt_rr+=p[i].wt;
				total_tat_rr+=p[i].tat;
				printf("   %d            %d              %d              %d               %d\n",
               				p[i].id, p[i].at, p[i].bt, p[i].wt, p[i].tat);
			}
			
			float AVG_WT=(float) total_wt_rr/(float) n;
			float AVG_TAT=(float) total_tat_rr/(float) n;
			
			
			printf("Average waiting time : %.2f \n",AVG_WT);
			printf("Avergae turn around time : %.2f \n",AVG_TAT);
			
			gantt_chart_rr(p,n,quantum);
			printf("\n");
			break;
			
		default:
			printf("Invalid choice");
			break;
	}
	return 0;
}
