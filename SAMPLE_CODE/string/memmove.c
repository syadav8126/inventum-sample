#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	void *a;
	void *b;
	b = malloc (10);
	a = malloc (10);
	printf("len:%ld\n",((long int)b-(long int) a));
	strcpy (b, "abcdefghi");
	memmove(a, b, 32);
	printf("%s\n",(char *) b);

}

