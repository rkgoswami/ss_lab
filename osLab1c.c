//To display content using readdir system call

#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>


int main(int argc,int *argv[])
{

	struct dirent *dptr;
	DIR *dname;
	
	if(argc!=2)
	{
		printf("\nUsage:./a.out <directory>");
		exit(-1);
	}
	
	if((dname=opendir(argv[1]))==NULL)
	{
		perror(argv[1]);
		exit(-1);
	}
	
	while(dptr=readdir(dname))
		printf("%s\n",dptr->d_name);
	
	closedir(dname);
	
}
