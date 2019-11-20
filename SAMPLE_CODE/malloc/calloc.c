#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a, b, *p;
	printf("enter the no of elements\n");
	scanf("%d",&a);
	p = (int *)calloc (a,4);
	for (int i=0; i<a; i++)
	{
		b =0;
		scanf ("%d",&b);
		*(p+i) = b;
	}
	for (int i=0; i<a ; i++){
		printf("%d\n",*(p+i));
	}
}
