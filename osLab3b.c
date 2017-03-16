#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
	FILE *fp;
	char str[100];
	char c;
	int i, flag, j, m, k,len;
	char temp[30];
	char *pos;
	if(argc != 3)
	{
		printf("Usage: gcc grep_command.c –o mygrep\n");
		printf("Usage: ./mygrep <search_text> <filename>\n");
		exit(-1);
	}
	fp = fopen(argv[2],"r"); // open the input file in readable mode.
	if(fp == NULL)
	{
		printf("%s is not exist\n",argv[2]);
		exit(-1);
	}
	while(!feof(fp)) 
	{
		i = 0;
		while(1)
		{
			c = fgetc(fp);
			if(feof(fp))
			{
				str[i++] = '\0';
				break;
			}
			if(c == '\n')
			{
				str[i++] = '\0';
				break;
			}
			str[i++] = c;
		}
		
		pos=strstr(str,argv[1]);
		if(pos!=NULL)
		{
			printf("\n%s",str);
		}
	}
	
	printf("\n");
	return 0;	
}
	
