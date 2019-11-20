#include <stdio.h>
#include <stdint.h>
int main()
{

	int a = 255 << 1;
/*
//nt a = 0x04030201;
	int a =1076895760;
	uint8_t b =a >> 24;*/
	printf("%d\n",a);
}
