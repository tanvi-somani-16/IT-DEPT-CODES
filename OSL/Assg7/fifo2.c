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
	int l=0,w=1,c=0;
	int i=0;
	char ch;
	
	//read from fifo1
	fd1=open(myfifo1,O_RDONLY);
	read(fd1,str1,sizeof(str1));
	printf("\n Pipe1 : %s",str1);
	close(fd1);
	
	while(str1[i]!='\0'){
		if(str1[i]=='.'||str1[i]=='\n'){
			l++;
		}
		else if(str1[i]==' '){
			w++;
		}
		else{
			c++;
		}
		i++;
	}
	
	printf("\n No of lines : %d",l);
	printf("\n No of words : %d",w);
	printf("\n No of characters : %d",c);
	
	FILE *fp=fopen("kp.txt","w");
	fprintf(fp,"\n No of lines : %d",l);
	fprintf(fp,"\n No of words : %d",w);
	fprintf(fp,"\n No of characters : %d",c);
	
	fclose(fp);
	
	//read from file
	fp=fopen("kp.txt","r");
	ch=fgetc(fp);
	i=0;
	while(ch!=EOF){
		str2[i]=ch;
		i++;
		ch=fgetc(fp);
	}
	str2[i]='\0';
	fclose(fp);
	
	//write from file
	fd2=open(myfifo2,O_WRONLY);
	write(fd2,str2,strlen(str2)+1);
	close(fd2);
	
	return 0;
}
