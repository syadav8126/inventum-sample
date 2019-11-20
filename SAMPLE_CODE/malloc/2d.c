#include <stdio.h>
#include <stdlib.h>
// malloc a 4*5 array	; 4 row: 5 column;
int main()
{
	int row = 4;
	int column = 5;
	char **a = (char **)malloc (row*(sizeof (char *)));
	for (int i=0; i < row; i++){
		a[i] =  (char *)malloc (column *(sizeof (char)));
	}
}

