#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int divide(int x, int y)
{
	if (y == 0)
	{
		printf("Error!! Divisible by 0");
		exit(1);
	}
	int sign = 1;
	if (x * y < 0)
		sign = -1;

	x = abs(x), y = abs(y);
	int quotient = 0;
	while (x >= y)
	{
	   x = x - y;		// perform reduction on dividend
	   quotient++;		// increase quotient by 1
	}
	printf("Remainder is %d\n", x);
	return sign * quotient;
}
int main(void)
{
	int dividend = 22;
	int divisor = -7;
	printf("Quotient is %d\n", divide(dividend, divisor));
	return 0;
}
