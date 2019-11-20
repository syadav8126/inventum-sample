/*
	I/p :: 2,1,2
	o/p :: cap=1
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct wa{
	int *arr;
	int count;
};

void find_capacity(struct wa* wat)
{
	int to_be_comp = (wat->arr[0] <= wat->arr[wat->count-1] ? wat->arr[0] : wat->arr[wat->count-1]);
	int cap=0;
	for(int i=1;i<wat->count;i++)
	{
		int a = to_be_comp-wat->arr[i];
		if(a>0)
			cap += a;
	}
	printf("cap is :%d\n",cap);
}

int main()
{
	struct wa *wat = (struct wa *)malloc(sizeof(struct wa));
	printf("Enter the num of elements\n");
	scanf("%d",&wat->count);
	wat->arr = (int *)malloc(sizeof(int *)*wat->count);
	printf("Enter the elements\n");
	for(int i=0;i<wat->count;i++)
	{
		scanf("%d",&wat->arr[i]);
	}
	find_capacity(wat);
}
