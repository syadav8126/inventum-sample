#include <stdio.h>
int main(){
	int c=3;
	long int cccc;
	cccc = (unsigned char) c;
	      cccc |= cccc << 8;
		        cccc |= cccc << 16;
	 cccc |= (cccc << 16) << 16;				
	printf("%ld\n",cccc);
}
