#include <stdio.h>
#include <stdlib.h>

struct list
{
	char file[20];
	int size;
	int start;
	int block[20];
}L[10];


int main()
{
	int n,i,j,len = 0,k,temp[20],blk,flag,st;
	
	printf("\nEnter the n value : ");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		fflush(stdin);
		printf("\nFile Name : ");
		scanf("%s",L[i].file);
		printf("\nNo. of blocks : ");
		scanf("%d",&L[i].size);
		
		printf("\nBlock List : ");
		
		for(j=0;j<L[i].size;++j)
		{
			printf("\nEnter the block %d :",j+1);
			scanf("%d",&blk);
			flag=0;
			for(k=0;k<len;++k)
			{
				if(temp[k]==blk)
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				L[i].block[j]=blk;
				temp[len++]=blk;
			}
			else
			{
				//repeat
				j--;
			}
		}//end of inner for
		//start block is a valid block or not
		printf("\nEnter the start block : ");
		scanf("%d",&st);
		while(1)
		{
			
			flag=0;
			for(j=0;j<L[i].size;++j)
			{
			//	printf("out flag=%d",flag);	
				if(st==L[i].block[j])
				{
					flag=1;
				//	printf("int flag=%d",flag);	
					break;
				}
			}
			if(flag==1)
			{
				L[i].start=st;
				break;
			}
			else
			{
				printf("\nPlz Enter a valid block :");
				scanf("%d",&st);
				continue;
			}
			
		}//while(1) end
	}//end of outer for		
	
	//display
	printf("\nFile\tSize\tStart\tLinked Block List\n\n");
	for(i=0;i<n;i++)
	{
		printf("\n\n%s \t %d \t %d \t %d-->",L[i].file,L[i].size,L[i].start,L[i].start);
		for(j=0;j<L[i].size;j++)
		{
			if(L[i].start == L[i].block[j])		
				continue;
			printf("%d-->",L[i].block[j]);
		}		
	}
		
		
}
