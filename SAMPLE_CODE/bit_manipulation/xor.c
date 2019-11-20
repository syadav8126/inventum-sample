#include <stdio.h>
int main()
{
	for (int a=0; a<2; a++)
	{
		for (int b=0; b<2;b++){
			int x = ((!a)*b) + (a*(!b));
			printf("\n%d\t	",a);
			printf("%d\t	",b);
			printf("%d	",x);
		}
		
	}
	printf("\n");
}
