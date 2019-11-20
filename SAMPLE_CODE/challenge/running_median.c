#include <stdio.h>
#include <stdlib.h>
int main()
{
	int count;
	int *arr = malloc(100);
	printf("Please enter the array\n");
	int i=0;
	float  med=0;
	while(1)
	{
		scanf("%d",&arr[i]);
		med=((med*(i))+arr[i])/(i+1);
		printf("Median is :%f\n",med);
		i++;
	}
}
