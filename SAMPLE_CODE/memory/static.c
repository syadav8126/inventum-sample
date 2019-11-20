#include <stdio.h>
#include "a.h"
static void aba()
{
	static sixe i;
	printf("ai is ::%d\n",i);
	i++;
}
void b()
{
	static int i;
	printf("bi is ::%d\n",i);
}
int main()
{
	int c;
	int *aa;
	c = 0;
	aa = (int *)c;
	a();
	b();
	a();
}
