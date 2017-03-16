//Simulation of LS

#include<stdio.h>	
#include<stdlib.h>
#include<string.h>
#include<dirent.h>

void main()
{
	struct dirent **namelist;
	int i,n;
	
	char pathname[100];
	getcwd(pathname);
	n=scandir(".",&namelist,0,alphasort);
	
	if(n<0)
	{
		printf("\nError");
	}
	else
	{
		for(i=0;i<n;++i)
		{
			if(namelist[i]->d_name[0]!='.')	
				printf("%s\n",namelist[i]->d_name);
			printf("\n");
			printf("%d\n",namelist[i]->d_ino);
		}
	}
			
}
