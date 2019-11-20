#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
int *p;
int a()
{
	printf("%d\n",*p);
	p += sizeof('A');
	printf("%d\n",*p);
	    return *p;
}
int main()
{
	p = (int *)malloc(10);
	printf("%d\n",a());
}
