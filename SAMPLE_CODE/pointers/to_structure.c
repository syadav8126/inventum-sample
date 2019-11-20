#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
	char name[21];	
	int age;
}rec;

void main(){
typedef rec *recpointer;
	recpointer r;
	r = (recpointer)malloc(sizeof(rec));
	strcpy(r->name, "dexter");
	printf("%s\n",(*r).name);
}

