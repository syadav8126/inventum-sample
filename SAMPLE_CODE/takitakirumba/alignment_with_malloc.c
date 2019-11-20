#include <stdio.h>
#include <stdlib.h>
void argument_alignment_check(long c1,long c2 ) 
{
// Considering downward stack 
// (on upward stack the output will be negative) 
printf("Displacement %ld\n", (long int)&c2 - (long int)&c1); 
} 

int main()
{
	long c,d;
	argument_alignment_check(c,d);
	char *a = malloc(10);
	char *b = malloc(10);
	printf("%p\n",a);
	printf("%p\n",b);
}
