#include <stdio.h>

typedef int (*multi)(int, int);

typedef	int (*add)(multi fn);

struct ll{
	add do_add;
};

int  multi1 (int a,int b){
	printf("In multi: %d\n",a*b);
}

int add1 (multi fn){
	return 1;
}

int main(){
	struct ll foo;
	foo.do_add = add1;
	multi fn = multi1;
	
	printf("ad:wqd is : %d\n",foo.do_add(fn(2,3)));
}
