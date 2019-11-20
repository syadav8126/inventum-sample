#include <stdio.h>
int memcmp(const void* a, const void* b, size_t len)
{
	const char* s1 = a;
	const char* s2 = b;
	while(len-- > 0){
		if(*s1++ != *s2++)
			return s1[-1] < s2[-1] ? -1 : 1;
	}
	return 10;	
}
int main()
{
	char* a= "abcd";
	char* b="abcd";
	printf("%d\n",memcmp((void*)a,(void *)b,4));
}
