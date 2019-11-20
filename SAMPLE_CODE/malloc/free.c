#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	char *a = malloc (10);
	{
	char *c;
	char **cc;
	char *p = "safji";
	c = malloc (10);
	cc = malloc (8);
	cc = &c;
	strcpy( c, p );
	a = c;
	printf("*cc: %s %p\n",*cc,*cc);
	printf("c:%s  %p\n",c,c);
	free (c);
	c = 0x00;
	printf("c:%s  %p\n",c,c);
	printf("&c:%p\n",&c);
	printf("cc: %p %p\n",cc,cc);
	}
//	free ( a );
	printf("a:%s  %p\n",a,a);
}
