#include <stdio.h>
#include <stdint.h>
int main(){
	uint32_t a=1;
	a = (a >> 1) ;
	if (a == 0)
		printf("little endian\n");
}
