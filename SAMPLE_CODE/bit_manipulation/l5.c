#include <stdio.h>
int main(){
	int a=10;
	int set = 10;
	int clear = 10;
	int toggle = 10;
	int b=1;
	clear &= ~b;    //clearing bit
	set |= b;	// setring bit
	toggle ^= b; 
	printf("%d\n",clear);
	printf("%d\n",set);
	printf("%d\n",toggle);


}
