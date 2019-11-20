#include <stdio.h>
char a ='r';
union father{
	long int add;
	char buf[8];
};
int main()
{
	union father son;
	printf("a is : %c\n",*&a);	
	son.add = (long int)&a;
	printf("son.add is : %c\n",*((char *)son.add));
	printf("add of a is: %p\n",&a);
	printf("son.buf is : %c\n",**(char **)son.buf);
	char **b = son.buf;
	printf("%c\n",**b);
}
