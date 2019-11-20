#include <stdio.h>
#include <setjmp.h>
jmp_buf this;

void adrak(void)
{
	int l = setjmp(this);
	printf("inside func l is : %d\n",l);
}

void lehsun(void)
{
	longjmp (this,2);
}


int main()
{	
	int i =0;
	adrak();
	if (i)
		printf("i is : %d\n",i);
	else 
	{
		longjmp(this,1);
	}
	lehsun();

}
