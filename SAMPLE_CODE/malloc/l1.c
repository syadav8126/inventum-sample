//own malloc
#include <assert.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
void func() {
fprintf(stdout, "sfdsdf");
}
void *malloc1(intptr_t size) {
	void *p = sbrk(0);
  void *request = sbrk(size);
	return p;
/*  if (request == (void*) -1) 
    return NULL;          // sbrk failed.
   else {
    assert(p == request); // Not thread safe.
    return p;
  }*/
}

void main(){
	char *p;
	p = malloc1(12);
	void *l = sbrk(10);
	printf("l:::%p\n",l);
//	free(p);
}
//fprintf(stderr, "sfdsdf  ");
