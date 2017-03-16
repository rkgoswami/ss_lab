//To create a file and write content 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
	int fd,n,len;
	char buf[100];
	
	if(argc!=2)
	{
		printf("\nUsage:./a.out <filename> ");
		exit(-1);
	}
	
	fd=open(argv[1],O_APPEND|O_WRONLY|O_CREAT,0644);
	
	if(fd<0)
	{
		printf("\nFile creation problem");
		exit(-1);
	}
	
	printf("\nPress Crtl+D at end in a new line :\n");
	
	while((n=read(0,buf,sizeof(buf)))>0)
	{
		len=strlen(buf);
		write(fd,buf,len);
	}
	
	close(fd);
} 
