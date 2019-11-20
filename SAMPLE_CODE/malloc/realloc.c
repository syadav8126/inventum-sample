#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	char *p1;
	int m1, m2;
	m1 = 0;
	m2 = 10;
	p1 = (char *)malloc(10);
	p1 = (char *)realloc(p1,0);
	strcpy(p1, "Goosdfjldsgbfskghshe");
//	strcat (p1, "LLC");
	printf("%s\n",p1);
}

