#include <stdio.h>
int main(){
	double a;
	printf("%d\n",__builtin_clzll(21));            //count leading zero
	printf("%d\n",__builtin_ctzll(21));            //count trailing zero
	printf("%d\n",__builtin_ffs(24));              //count trailing zero + 1
	printf("%d\n",__builtin_popcount(25));         //return no of 1's
	printf("%d\n",__builtin_parity(3));            //return parity
	printf("%f\n",__builtin_powi(a,7));            //
	return 0;
}
