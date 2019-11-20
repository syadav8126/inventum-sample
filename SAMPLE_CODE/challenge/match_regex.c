/*
	i/p :: .*at,cat
	o/p :: matched 1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
struct reg{
	int period;
	int star;
	char *token;
	char* str;
	char* to_be_match;
	int result;
};

void string_man(struct reg *regex)
{
	int i=0;
	while(regex->token[i] != '\0')
	{
		switch(regex->token[i++])
		{
			case '.':
				regex->period = 1;
				break;
			case '*':
				regex->star = 1;
				break;
			default:
				break;
		}
	}
}

void match_cmp(struct reg* regex)
{
	int i=0;
	int l = strlen(regex->to_be_match);
	int L = strlen(regex->str);
	while(regex->to_be_match[i++] != '\0')
	{
		strlen(regex->str);
		if(regex->str[L-l+i] != regex->to_be_match[i])
		{
			regex->result = 0;
			return;
		}
		else 
			regex->result = 1;
			
	}
}

void find_match(struct reg* regex)
{
	int i=0;
	char *tmp = (char *)malloc(100);
	if(regex->star)
	{
		while(regex->token[i++] != '*');
		strcpy(regex->to_be_match,&regex->token[i]);
	}
	match_cmp(regex);
}

int main()
{
	struct reg* regex;
	regex = (struct reg*) malloc (sizeof(struct reg));
	regex->token =  malloc (100);
	regex->str =  malloc (100);
	regex->to_be_match =  malloc (100);
	printf("Enter String\n");
	scanf("%s",regex->str);
//	strcpy(regex->token,"...*di");
	char *str = (char *)malloc(100);
	printf("Enter Token\n");
	scanf("%s",regex->token);
//	strcpy(regex->str,"guddi");
	string_man(regex);
	find_match(regex);
	printf("%d\n",regex->result);
}
