#include <stdio.h>
#include <alloca.h>
int main(){
	char *a=NULL,*b=NULL;
	int i;
	for(i=1;i<40;i++){
	a = alloca(i);
	printf("%d:%ld\n",i,(((long int)a) - ((long int) b)));
	b = a;
//	printf("%ld\n",(long int)a);
//	printf("%d: %ld\n",i,(long int)a);
	}
}
