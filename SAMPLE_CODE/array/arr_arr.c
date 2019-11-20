#include <stdio.h>
#include <stdlib.h>
int main()
{
	int arr[2][3];
	for (int i=0;i<2;i++)
		for(int j=0;j<3;j++)
		{
			printf("%d\n",rand());
			arr[i][j]=rand();
		}
}
