#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
int32_t ChangeEndianness(uint32_t u32Value)
{
	uint32_t u32Result = 0;

	u32Result |= (u32Value & 0x000000FF) << 24;
	u32Result |= (u32Value & 0x0000FF00) << 8;
	u32Result |= (u32Value & 0x00FF0000) >> 8;
	u32Result |= (u32Value & 0xFF000000) >> 24;


	return u32Result;
}

int main()
{
	uint32_t u32CheckData  = 0x11223344;
	uint32_t u32ResultData =0;
	int32_t  i = 1; 
	printf("%p\n",&i);
	u32ResultData = ChangeEndianness(&i);  //connverted in big endian
	printf("0x%xn\n",u32ResultData);
	u32CheckData = u32ResultData;
	printf("%p\n",&i);
	char *c = (char*)&u32ResultData; 
	if (*c)     
		printf("Little endian\n"); 
	else
		printf("Big endian\n"); 
	return 0;
}
