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
	
	fd=open(argv[1],O_RDONLY);
	
	if(fd<0)
	{
		printf("\nFile creation problem");
		exit(-1);
	}
	
	printf("\nPress Crtl+D at end in a new line :\n");
	
	while(read(fd,buf,sizeof(buf))>0)
	{
		printf("%s",buf);
	}
	
	close(fd);
} 
