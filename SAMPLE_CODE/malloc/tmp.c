#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
int  * a;
int ** c;
int main()
{
	a = (int *)malloc(1);
	c = &a;
	if(a)
		free(a);
	a = NULL;
	if(*c)
		free(*c);
}
