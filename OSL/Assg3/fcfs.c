#include<stdio.h>
#include<stdlib.h>

struct process{
	int id;
	int at;
	int bt;
	int wt;
	int tat;
};

void fcfs(struct process p[],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(p[j].at>p[j+1].at){
				struct process temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	}
}

void WT(struct process p[],int n){
	int service_time[n];
	service_time[0]=p[0].at;
	p[0].wt=0;//waiting time for first process is zero
	
	for(int i=1;i<n;i++){
		service_time[i]=service_time[i-1]+p[i-1].bt;
		p[i].wt=service_time[i]-p[i].at;
		
		if(p[i].wt<0){
			p[i].wt=0;
		}
	}	
}

void TAT(struct process p[],int n){
	for(int i=0;i<n;i++){
		p[i].tat=p[i].bt+p[i].wt;
	}
}

void avgtime(struct process p[],int n){
	int total_wt=0,total_tat=0;
	//Sort process
	fcfs(p,n);
	
	//find waiting time
	WT(p,n);
	
	//Fint TAT
	TAT(p,n);
	
	printf("Processes    Arrival Time    Burst Time    Waiting Time    Turn Around Time \n");
	for(int i=0;i<n;i++){
		total_wt=total_wt+p[i].wt;
		total_tat=total_tat+p[i].tat;
		
		printf("   %d            %d              %d              %d               %d\n",
               p[i].id, p[i].at, p[i].bt, p[i].wt, p[i].tat);
	}
	
	float avg_wt=(float)total_wt/(float)n;
	float avg_tat=(float)total_tat/(float)n;
	
	printf("Total Average Waiting time is %.2f\n",avg_wt);
	printf("Total Turn Around Time is %.2f\n",avg_tat);
	
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

int main(){
	struct process proc[] = {{1, 8, 10}, {2, 1, 5}, {3, 4, 8}}; 
    int n = sizeof(proc) / sizeof(proc[0]);

    avgtime(proc, n);
    return 0;
}






























