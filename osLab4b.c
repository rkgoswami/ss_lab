#include<stdio.h>
#include<stdlib.h>

struct process
{
	int pid;
	int btime;
	int wtime;
	int ttime;
}p[10],temp;

int main()
{
	int i,j,k,n,ttur,twat;
	float awat,atur;
	
	// read number of processes and their burst times.
	printf("Enter no. of process: ");
	scanf("%d", &n);
	printf("READ BURST TIMES..........\n");
	for(i=0; i<n; i++)
	{
		printf("Burst time for process P%d (in ms): ",(i+1));
		scanf("%d", &p[i].btime);
		p[i].pid = i+1;
	}
	
	//sort increasing order the process
	for(i=0;i<n;++i)
	{
		for(j=i+1;j<n;++j)
		{	
			if((p[i].btime > p[j].btime ) || ( (p[i].btime==p[j].btime) && (p[i].pid>p[j].pid) ) )
			{
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;	
			}
		}
	}	
	
	//calculate the wtime and ttime
	p[0].wtime=0;
	for(i=0;i<n;++i)
	{
		p[i+1].wtime=p[i].wtime+p[i].btime;
		p[i].ttime=p[i].wtime+p[i].btime;
	}
	
	//calculate the total ttime and twat
	ttur=0;
	twat=0;
	for(i=0;i<n;++i)
	{
		ttur+=p[i].ttime;
		twat+=p[i].wtime;
	}
	
	// to print process table
	printf("\nSJF Scheduling\n\n");
	
	for(i=0; i<28; i++)
		printf("-");
	
	printf("\nProcess B-Time T-Time W-Time\n");
	for(i=0; i<28; i++)
	printf("-");

	for(i=0; i<n; i++)
	printf("\n P%d\t%4d\t%3d\t%2d",p[i].pid,p[i].btime,p[i].ttime,p[i].wtime);
	printf("\n");
	for(i=0; i<28; i++)
	printf("-");
	
	
	printf("\nAverage turn around time : %f",ttur/(float)n);
	printf("\nAverage waiting time : %f",twat/(float)n);
	
	printf("\n");
	
	//print gantt chart
	for(i=0;i<n;++i)
	{
		printf("|");
		for(j=0;j<p[i].ttime;++j)
		{
			if(j==(p[i].ttime/2))
				printf("P%d",i);
			printf(" ");
		}
	}
	k=0;
	printf("|\n");
	for(i=0;i<=n;++i)
	{
		
		printf("%d",k);
		for(j=0;j<p[i].ttime+2;++j)
		{
			printf(" ");
		}
		k=p[i].ttime;
	}
	
	printf("\n");
	return 0;
	
	
}

	
		
		
		
