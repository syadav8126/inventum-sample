#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *strdup(const char *s){
	void *s1;
	int size = strlen(s);
	s1 = malloc(size);
	return memcpy(s1,(void *)s,size);	
}


int main(){
	char *s=NULL;
	s = malloc (10);
	strcpy(s,"jlo ek din degi");
	printf("%s\n",strdup(s));



}
