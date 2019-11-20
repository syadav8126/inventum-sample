#include <stdio.h>
#include <stdlib.h>
int main(){
	int d = 1;
	char g = 'a';
	int l[10];
	printf("d %p\n",&d);   //memory will always be  allocated to char than int
	printf("g %p\n",&g);
	printf("l %p\n",&l);
}
