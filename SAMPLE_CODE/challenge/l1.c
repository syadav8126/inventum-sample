/*
I/p::::   a1b22c3d6a4
o/p::::   a4b22c3d6
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct a{
	char al;
	int count;
};

struct a arr[100];
char *st;
int j=0;
int offset=0;

int check_if_exist(char ch)
{
	for(int i=0;i<j;i++)
		if(ch == arr[i].al)
			return i;
	return -1;
}
char get_key(int off)
{
	offset++;
	return st[off];
}
int get_value()
{
	int num=0,num1=0;
	while(st[offset]>='0' && st[offset]<='9')
	{
		num1 = st[offset] - '0';
		num = num*10 + num1;
		offset++;
	}
	return num;
}
void populate_arr()
{
	char ch;
	int value=0;
	for(offset=0;offset<strlen(st);offset)
	{	
		ch = get_key(offset);
		value = get_value();
		int ret = check_if_exist(ch);
		if(ret>-1)
		{
			arr[ret].count += value;
			
		}
		else
		{
			arr[j].al = ch;
			arr[j].count = value;
			j++;
		}
	}
}
void printf_arr()
{
	for(int i=0;i<j;i++)
		printf("%c%d\n",arr[i].al,arr[i].count);
}
int main()
{
	st = (char *)malloc(1000);
	strcpy(st,"a1b2c3a4b455");
//	printf("Enter The string with int and char count \n");
//	scanf("%s",st);
	populate_arr();
	printf_arr();
}
