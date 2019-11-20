#include <stdio.h>
#include <string.h>
int main(){
	{{long int a=111111;

	printf("%ld\n",a);
	memset(&a,0,1);	
	printf("%ld\n",a);}}
}
