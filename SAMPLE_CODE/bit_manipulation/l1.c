#include <stdio.h>
#include <stdint.h>
int main(){
	uint32_t a=2134224211232;
	printf("%ld\n",a & 0xffffffffffffffff);
	a = a & 0xffffffffffffffff;
	printf("%ld\n",a);
	

}
