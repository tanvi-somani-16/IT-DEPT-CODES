#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int track,no_req,head,head1,distance;
int dis_req[100],finish[100];

void input(){
	printf("Enter the number of tracks : ");
	scanf("%d",&track);
	printf("Enter the number of requests : ");
	scanf("%d",&no_req);
	printf("Enter the requests : ");
	for(int i=0;i<no_req;i++){
		scanf("%d",&dis_req[i]);
	}
	printf("Enter initial head position : ");
	scanf("%d",&head1); 
}

void sstf(){
	int min,diff;
	int pending=no_req;
	head=head1;
	distance=0;
	
	for(int i=0;i<no_req;i++){
		finish[i]=0;
	}
	
	while(pending > 0) {
        min = 9999;
        int index;
        for(int i = 0; i < no_req; i++) {
            diff = abs(head - dis_req[i]);
            if(finish[i] == 0 && diff < min) {
                min = diff;
                index = i;
            }
        }
        finish[index] = 1;
        distance += abs(head - dis_req[index]);
        head = dis_req[index];
        pending--;
        printf("%d => ", head);
    }
    printf("end\n");
    printf("Total distance travelled = %d\n", distance);	
}

void sort() {
    for(int i = 0; i < no_req; i++) {
        for(int j = i + 1; j < no_req; j++) {
            if(dis_req[i] > dis_req[j]) {
                int temp = dis_req[i];
                dis_req[i] = dis_req[j];
                dis_req[j] = temp;
            }
        }
    }
}

void scan() {
    int index, dir;
    distance = 0;
    head = head1;

    printf("Enter direction (1 for right, 0 for left): ");
    scanf("%d", &dir);
    sort();

    int i = 0;
    while (head >= dis_req[i] && i<no_req) {
        index = i;
        i++;
    }
    printf("\n%d =>", head);

    if (dir == 1) {
        for (i = index + 1; i < no_req; i++) {
            printf("%d =>", dis_req[i]);
            distance += abs(head - dis_req[i]);
            head = dis_req[i];
        }
        distance += abs(head - (track - 1));
        printf("%d => ", track - 1);
        head = track - 1;

        for (i = index; i >= 0; i--) {
            printf("%d =>", dis_req[i]);
            distance += abs(head - dis_req[i]);
            head = dis_req[i];
        }
    } else {
        for (i = index; i >= 0; i--) {
            printf("%d =>", dis_req[i]);
            distance += abs(head - dis_req[i]);
            head = dis_req[i];
        }
        distance += abs(head - 0);
        printf("%d => ", 0);
        head = 0;

        for (i = index + 1; i < no_req; i++) {
            printf("%d =>", dis_req[i]);
            distance += abs(head - dis_req[i]);
            head = dis_req[i];
        }
    }
    printf("end\n");
    printf("Total distance travelled = %d\n", distance);
}

void c_look() {
    int index, dir;
    distance = 0;
    head = head1;

    printf("Enter direction (1 for right, 0 for left): ");
    scanf("%d", &dir);
    sort();

    int i = 0;
    while (head >= dis_req[i] && i<no_req) {
        index = i;
        i++;
    }
    printf("\n%d =>", head);

    if (dir == 1) {
        for (i = index + 1; i < no_req; i++) {
            printf("%d =>", dis_req[i]);
            distance += abs(head - dis_req[i]);
            head = dis_req[i];
        }

        for (i = 0 ;i <=index; i++) {
            printf("%d =>", dis_req[i]);
            distance += abs(head - dis_req[i]);
            head = dis_req[i];
        }
    } else {
        for (i = index; i >= 0; i--) {
            printf("%d =>", dis_req[i]);
            distance += abs(head - dis_req[i]);
            head = dis_req[i];
        }

        for (i = no_req-1; i >index; i--) {
            printf("%d =>", dis_req[i]);
            distance += abs(head - dis_req[i]);
            head = dis_req[i];
        }
    }
    printf("end\n");
    printf("Total distance travelled = %d\n", distance);
}

int main(){
	int choice;
	input();
	
	int flag=1;
	
	while(flag!=0){
		printf("1.SSTF\n2.SCAN\n3.C-LOOK\n");
		printf("Enter choice : ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				sstf();
				break;
			case 2:
				scan();
				break;
			case 3:
				c_look();
				break;
			case 4:
				printf("Exit\n");
				flag=0;
				break;
			default:
				printf("Enter valid option");
				break;
		}
	}
	return 0;
}
