#include <stdio.h>

int main(){


	int a=0,b=0,c=0;
	scanf("%d %d",&a,&b);
	while(b!=0){
	if (__builtin_ctzll(b)){   //if b is even
	}
	else {
		c = c | a;
}
	a = a << 1;
	b = b >> 1;
}
	printf("%d\n",c);
	return 0;
}
