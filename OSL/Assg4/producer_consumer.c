#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

#define SIZE 10

typedef struct queue{
	int arr[SIZE];
	int in;
	int out;
	sem_t full;
	sem_t empty;
	pthread_mutex_t lock;
}queue;

queue buffer;
int item=1;

void* producer(void* arg){
	//index stored the producer id and z generated a random delay
	int index,z;
	index=*(int*)arg;
	int value;
	
	while(1){
		z=(rand()%10)+1;
		sleep(z);
		sem_wait(&buffer.empty);//decrementing the empty value
		sem_getvalue(&buffer.empty,&value);
		
		if(value==0){
			printf("\nBuffer is full.\n\n Producer is waiting to produce item.\n\n");
		}
		
		pthread_mutex_lock(&buffer.lock);
		printf("\n\n Producer %d is producing item %d",index,item);
		buffer.arr[(buffer.in++)%SIZE]=item++;
		pthread_mutex_unlock(&buffer.lock);
		sem_post(&buffer.full);
	}
}

void* consumer(void* arg){
	//index stored the producer id and z generated a random delay
	int index,z;
	int cons;
	index=*(int*)arg;
	int value;
	
	while(1){
		z=(rand()%10)+4;
		sleep(z);
		sem_wait(&buffer.full);
		sem_getvalue(&buffer.empty,&value);
		
		if(value==SIZE){
			printf("\nBuffer is empty.\n\n Consumer is waiting to consume item.\n\n");
		}
		
		pthread_mutex_lock(&buffer.lock);
		cons=buffer.arr[(buffer.out++)%SIZE];
		printf("\n\n Consumer %d is consuming item %d",index,item);
		
		pthread_mutex_unlock(&buffer.lock);
		sem_post(&buffer.empty);
	}
}

void init(){
	buffer.in=0;
	buffer.out=0;
	sem_init(&buffer.full,0,0);
	sem_init(&buffer.empty,0,SIZE);
}

void main(){
	int i;
	pthread_t consumer_t[SIZE],prod_t[SIZE];
	
	int nprod,ncons;//number of producers and consumers
	
	init();
	
	printf("Enter the number of producers : ");
	scanf("%d",&nprod);
	
	printf("Enter the number of consumers : ");
	scanf("%d",&ncons);
	
	//create producer threads
	for(i=0;i<nprod;i++){
		pthread_create(&prod_t[i],NULL,*producer,&i);
		printf("\nProducer %d starting \n",i);
	}
	
	//create consumer threads
	for(i=0;i<ncons;i++){
		pthread_create(&consumer_t[i],NULL,*consumer,&i);
		printf("\nConsumer %d starting\n",i);
	}
	
	//wait for all producer threads to complete
	for(i=0;i<nprod;i++){
		pthread_join(prod_t[i],NULL);
	}
	
	//wait for all consumer threads to complete
	for(i=0;i<ncons;i++){
		pthread_join(consumer_t[i],NULL);
	}
	
}
