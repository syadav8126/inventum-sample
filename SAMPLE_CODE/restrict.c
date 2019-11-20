#include <stdio.h>
void aaa(int *restrict a, int **restrict b)
{
	*a = 20;
	printf("%d-%d-\n",*a,**b);	
}
int main(void) 
{
	int c =10;
	int *a = &c;
	int **b = &a;
	aaa(&c,&a);
	printf("%d=%d\n",*a,**b);
//	*a = 20;
//	c =30;
//	printf("*a=%d,*b=%d\n",*a,*b);
}
