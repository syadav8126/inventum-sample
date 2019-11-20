#include <stdio.h>
#include <stdlib.h>
extern int etext,edata,end;
int main(){
	printf("edata: %ld\n",(long int)&edata);
	printf("etext: %ld\n",(long int)&etext);
	printf("end: %ld\n",(long int)&end);
	char *s1 = "hello"; //in initialized data segmenta
	static int a=1; //in initialized data segment
	static int b; //in uninitialized data segment
	char s2[] = "hello"; //in the stack area.
	printf("s1: %ld\n",(long int) s1);
	printf("a: %ld\n",(long int) &a);
	printf("b: %ld\n",(long int) &b);
	printf("s2: %ld\n",(long int) s2);
}
