#include<stdio.h>
#include<stdlib.h>

int main()
{
	int b[10],a[10],tempBt[10],ne[10],fList[30],et[30];
	int wt[10]={0};
	int n, i,j,k;
	int sum=0,ts,pn;
	int l=0,flag,t;
	// reading the burst times of each processes.
	printf("\nEnter the number of processes : ");
	scanf("%d",&n);
	for(i=0; i<n; i++)
	{
		printf("Enter the burst time of process P%d : ",i+1);
		scanf("%d",&b[i]);
		tempBt[i]=b[i];
	}

	// reading time quantum/slice.
	printf("Enter the time slice in ms: ");
	scanf("%d",&ts);	
	
	//calculate no. of premtions
	for(i=0;i<n;++i)
	{
		ne[i]=b[i]/ts;
		if(b[i]%ts != 0)
			ne[i]+=1;
		
		sum+=ne[i];
	}
	
	//process execution based on time quantum
	
	while(1)
	{
		flag=1;
		for(i=0;i<n;++i)
		{
			if(b[i]>0 && ne[i]>0)
			{
				fList[l]=i;		//sequence in which process occur
				
				if(b[i]<ts)
					et[l++]=b[i];		//execution time of each time quantum based process
				else
					et[l++]=ts;
			
				b[i]=b[i]-ts;	//burst time of process after getting reduced
				
				ne[i]=ne[i]-1;
			}
			
			if(ne[i]!=0)		//only be execute when all processes have done their times of execution
				flag=0;
		}
		if(flag)
			break;
	}
				
				
	//logic to generate the gantt chart
	
	printf("\nRound Robin Scheduling :");
	printf("\n=========================");
	
	//printf("\nL=%d",l);
	
	printf("\nGantt chart\n");
	for(i=0;i<l;++i)
	{	
		printf("|");
		for(j=0;j<et[i];++j)
		{
			if(j==(et[i]/2))
				printf("P%d",fList[i]+1);
			printf(" ");
		}
	}
	printf("|\n0");
	t=0;
	for(i=0;i<l;++i)
	{	
		for(j=0;j<et[i]+2;++j)
		{
			printf(" ");
		}
		t+=et[i];
		printf("%d",t);
	}
	printf("\n");

	//calculation of turnaround time 
	
	pn=0;
	
	while(pn<n)
	{
		flag=0;
		for(i=l-1;i>=0;--i)
		{
			if(fList[i]==pn)
			{
				flag=1;
				continue;
			}
			if(flag)
				wt[pn]=wt[pn]+et[i];
		}
		pn++;
	}
	
	//process table
	for(i=0; i<28; i++)
		printf("-");
	
	printf("\nProcess B-Time T-Time W-Time\n");
	for(i=0; i<28; i++)
	printf("-");

	for(i=0; i<n; i++)
	printf("\n P%d\t%4d\t%3d\t%2d",i+1,tempBt[i],wt[i],wt[i]+tempBt[i]);
	printf("\n");
	for(i=0; i<28; i++)
	printf("-");
	
	
	//printf("\nAverage turn around time : %f",ttur/(float)n);
	//printf("\nAverage waiting time : %f",twat/(float)n);
		

	return 0;		
}
