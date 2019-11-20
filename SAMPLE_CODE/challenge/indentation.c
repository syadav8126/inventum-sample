#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct in{
	char **str;
	int line;
	int* larr;
	int element;
};

void indent(struct in* ind)
{
	int length=0;
	int i=0;
	for(i=0;i<ind->element;i++)
	{
		ind->larr[i] = strlen(ind->str[i]);
	}
	i=0;
	for(i=0;i<ind->line,length<ind->line;i++)
//	while(length<ind->line)
	{
		length += ind->larr[i];
		length++;
	}
	printf("%d\n",length);
}

int main()
{
	struct in* ind = (struct in*)malloc(sizeof(struct in));
	ind->element = 9;
	ind->str = (char **) malloc(sizeof(struct ind*)*11);
	ind->larr = (int *)malloc(sizeof(int *)*ind->element);
	
//	printf("Enter the nu of strings\n");
	for(int i=0;i<(ind->element);i++)
	{
		ind->str[i] = malloc(10);
	}
	strcpy(ind->str[0],"cant");
	strcpy(ind->str[1],"connect");
	strcpy(ind->str[2],"to");
	strcpy(ind->str[3],"konfd");
	strcpy(ind->str[4],"socket");
	strcpy(ind->str[5],"do");
	strcpy(ind->str[6],"show");
	strcpy(ind->str[7],"running");
	strcpy(ind->str[8],"config");
	ind->line = 14;
	indent(ind);	
}
