#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i,j,len,refStr[50],frame[10],nf;
	int freq=0;
	int k;
	printf("Enter the no. of pages : ");
	scanf("%d", &len);
	
	printf("Enter reference string :\n");
	for(i=0; i<len; i++)
		scanf("%d", &refStr[i]);

	printf("Enter no. of frames : ");
		scanf("%d", &nf);

	for(i=0; i<nf; i++)
		frame[i] = -1;
	
	
	printf("\nRef.str Page frames\n");
	frame[freq]=refStr[0];
	printf("\n\t%d",frame[freq]);
	freq++;
	for(i=1;i<len;++i)	//for each element of reference string
	{
		for(j=0;j<nf;++j)
		{
			if( refStr[i]==frame[j] )
				break;
		}
		
		if(j==nf)	//then element does not exist 
		{
			frame[freq]=refStr[i];
			freq=(freq+1)%nf;
		 }		 
		printf("\n");
		for(j=0;j<nf;++j)
			printf("\t%d",frame[j]);	
		
		
	}
	printf("\n");			
	return 0;
}
