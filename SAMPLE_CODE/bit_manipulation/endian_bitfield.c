#include <stdio.h>
#include <stdint.h>
        struct a{
            unsigned short a : 1;
            unsigned short b : 2;
            unsigned short c : 3;
            unsigned short d : 4;
            unsigned short e : 5;
        } field;
int main()
{
	field.a = 1;
	field.b = 2;
	field.c = 3;
	field.d = 4;
	field.e = 5;
	printf("%d\n",field.a);	
	printf("%d\n",field.b);	
	printf("%d\n",field.c);	
	printf("%d\n",field.d);	
	printf("%d\n",field.e);	
}
