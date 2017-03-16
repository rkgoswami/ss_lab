#include<stdio.h>
#include<stdlib.h>

void first_fit(int bArr[],int bSize,int hole[],int hSize)
{
	int intF=0,extF=0;
	int i,j,k;
	int flag[30]={0};
	
	for(i=0;i<bSize;i++)
	{
		for(j=0;j<hSize;j++)
		{
			if((flag[j]==0) && (bArr[i]<=hole[j]) )
			{
				flag[j]=1;
				intF+=(hole[j]-bArr[i]);
				break;		
			}
			
		}
		if(j==hSize)
		{
			printf("\nThere is no space for the process %d",i);
		}
	}	
	
	//caalculate external fragmentation
	
	for(i=0;i<hSize;++i)
	{
		if(flag[i]==0)
			extF+=hole[i];
	}
	
	printf("\nInternal Fragmentation : %d",intF);
	printf("\nExternal Fragmentation : %d",extF);

}

void sortHole(int p[],int n)
{
	int temp,i,j;
	//sort increasing order the holes
	for(i=0;i<n;++i)
	{
		for(j=i+1;j<n;++j)
		{	
			if( ( p[i] > p[j] ) )
			{
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;	
			}
		}
	}	
}


int main()
{
	int hole[10],bArr[10];
	int i,j,bSize,hSize;
	
	printf("\nEnter the no. of process :");
	scanf("%d",&bSize);
	
	printf("\nEnter the burst time of processes :");
	for(i=0;i<bSize;++i)
	{	
		printf("Process %d:",i+1);
		scanf("%d",&bArr[i]);
	}
	
	printf("\nEnter the no.of holes :");
	scanf("%d",&hSize);
		
	printf("\nEnter the size of holes :");
	for(i=0;i<hSize;++i)
	{	
		printf("Holes %d:",i+1);
		scanf("%d",&hole[i]);
	}
	
	sortHole(hole,hSize);	
	first_fit(bArr,bSize,hole,hSize);
	
	return 0;
}
