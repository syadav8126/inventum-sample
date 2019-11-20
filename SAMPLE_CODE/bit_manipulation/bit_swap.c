#include <stdio.h>
void swap(int a)
{
	a = (a &0b10101010) >>1 | (a & 0b01010101) <<1;
	printf("%d\n",a);
}
int main()
{
	int a=55;
	swap(a);
}
