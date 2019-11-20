#include <stdio.h>
#include <stdint.h>
int main(){
	uint32_t x =100;
	uint32_t key = ((x & 0xfff) << 16);
	printf("%d\n",key);

}
