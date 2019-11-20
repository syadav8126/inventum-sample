#include <stdio.h>
#include <stdint.h>
int main()
{
	uint64_t n;
	uint64_t sum=0;
	n = 999999;
	sum = (n*(n+1))/2;
/*	for (int i =0;i <n ; i++)
	{
		sum += i;
	}
*/	printf("%ld\n",sum);
}
