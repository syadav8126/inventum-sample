#include <stdio.h>
#include <string.h>
int main(){
	int c;
	char a[4];
	char b[4];
	char fd[4];

	strcpy(a,"c");
	strcpy(b,"uda");
	strcpy(fd,"aaa");
	printf("   %p \n",__builtin_frame_address(0));
	printf("fd:%p\n",fd);
	printf("b: %p\n",b);
	printf("a: %p\n",a);
	printf("c: %p\n",&c);

}
