#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	char *p="ansh";
	printf("%p\n",p);
	p = malloc (10);
	printf("%p\n",p);
	strcpy(p,"anshu");
	printf("%s\n",p);
	printf("%p\n",__builtin_frame_address(0));
	printf("csf:%p\n",({ char __csf; &__csf; }));
}
