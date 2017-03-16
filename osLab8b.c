#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i,j,len,refStr[50],frame[10],nf;
	int lru[10], freq=0, min ;
	
	printf("Enter the no. of pages : ");
	scanf("%d", &len);
	
	printf("Enter reference string :\n");
	for(i=0; i<len; i++)
		scanf("%d", &refStr[i]);

	printf("Enter no. of frames : ");
		scanf("%d", &nf);

	for(i=0; i<nf; i++)
		frame[i] = -1;
	
	for(i=0; i<10; i++)
		lru[i] = 99;

	
	printf("\nRef.str Page frames");
	frame[freq]=refStr[freq];
	
	printf("\n\t%d",frame[freq]);
	freq++;
	
	for(i=1;i<len;++i)	//for each element of reference string
	{
		//search if the element exist already in the frame
		for(j=0;j<nf;++j)
		{
			if( refStr[i]==frame[j] )
				break;
		}
		
		lru[refStr[i]]=i;
		if(j==nf)	//then element does not exist 
		{
			if(freq<nf)	//empty space is there in frame
			{
				frame[freq]=refStr[i];
				freq++;			
			}
			else 
			{
				//find lru
				min=0;
				for(j=0;j<len;++j)
				{
					if(lru[min] > lru[j])
						min=j;
				}	
				for(j=0;j<nf;++j)
				{
					if(frame[j]==min)
						frame[j]=refStr[i];
				}
			 }//else	
			 
		}//end of if outer
		printf("\n");
		for(j=0;j<freq;++j)
			printf("\t%d",frame[j]);	
		
	 		
	}
	printf("\n");			
	return 0;
}
