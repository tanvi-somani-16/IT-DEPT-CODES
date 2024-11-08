#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<unistd.h>
#include<pthread.h>

#define max 10

int readcount,var;//readcount is the number of active readers and var is shared varibale 
sem_t writer,reader;
pthread_mutex_t lock;

void init(){
	pthread_mutex_init(&lock,NULL);
	sem_init(&writer,0,1);
	sem_init(&reader,0,0);
	readcount=0;
	var=0;
}

void* readerFunc(void* args){
	//int index,z;
	//index=*(int*)args;
	int z;
	while(1){
		z=(rand()%10)+4;
		sleep(z);
		pthread_mutex_lock(&lock);
		readcount++;
		if(readcount==1)
			sem_wait(&writer);
		pthread_mutex_unlock(&lock);
		
		printf("\n Reading is performed and the value read is : %d\n ", var);
		
		pthread_mutex_lock(&lock);
		readcount--;
		if(readcount==0)
			sem_post(&writer);
		pthread_mutex_unlock(&lock);
		//sleep(1);
	}
}

void* writerFunc(void* args){
	//int index;
	int z;
	//index=*(int*)args;
	while(1){
		z=(rand()%10)+1;
		sleep(z);
		sem_wait(&writer);
		var++;
		printf("\n Writing is performed and the value changed to : %d\n",var);
		sem_post(&writer);
		//sleep(1);
	}
}

int main(){
	int read,write,i;
	pthread_t reads[max],writes[max];
	
	init();
	
	printf("Enter the number of readers : ");
	scanf("%d",&read);
	printf("Enter the number of writers : ");
	scanf("%d",&write);
	
	//create writer threads
	for(i=0;i<write;i++){
		 pthread_create(&writes[i], NULL,*writerFunc, &i);
     	 printf("\n\nWriters %d starting\n\n",i);
	}

	//create reader threads
	for(i=0;i<read;i++){
		 pthread_create(&reads[i], NULL,*readerFunc, &i);
     	 printf("\n\nReaders %d starting\n\n",i);
	}
	
	//join writer threads
	for(i=0;i<write;i++){
		pthread_join(writes[i], NULL);
	}
	
	//join reader threads
	for(i=0;i<read;i++){
		pthread_join(reads[i], NULL);
	}
	return 0;
}




