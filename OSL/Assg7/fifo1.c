 #include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
	int fd1,fd2;
	char myfifo1[]="file1";
	char myfifo2[]="file2";
	char str1[100],str2[100];
	
	mkfifo(myfifo1,0666);
	mkfifo(myfifo2,0666);
	
	printf("Enter the string : ");
	fgets(str1,100,stdin);
	
	//write to first fifo pipe
	fd1=open(myfifo1,O_WRONLY);
	write(fd1,str1,strlen(str1)+1);
	close(fd1);
	
	//read from seconf fifo pipe
	fd2=open(myfifo2,O_RDONLY);
	read(fd2,str2,100);
	printf("Get message from fifo 2 : \n %s",str2);
	close(fd2);
	
	return 0;
}
