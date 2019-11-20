#include <stdio.h>
#include <stdlib.h>
int main()
{
	static int  a=101111;
	int* aa = (int *)malloc(8);
	aa = &a;
	printf("value at a:%p\n",*aa);
}
