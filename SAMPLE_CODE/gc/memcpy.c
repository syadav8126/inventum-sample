#include <stdio.h>
#include <stdlib.h>

void* memcpy(void* dest, const void* src, size_t len)
{
	char* s1 = dest;
	const char* s2 = src;
	while(len--)
	{
		*s1++ = *s2++;
	}
	return dest;
}

int main()
{
	char* a = "abcd";
	const char* b = malloc (10);
	memcpy(b,a,2);
	printf("%s\n",b);
}
