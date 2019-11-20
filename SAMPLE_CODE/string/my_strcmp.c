#include <stdio.h>
int strcmp(const char *s1,const char *s2){
	unsigned char c1, c2; 
	unsigned char *p1 = (const unsigned char *)s1;
	unsigned char *p2 = (const char *)s2;
	do{
		c1 = *p1++;
		c2 = *p2++;
		if (c1 == '\0')
			return c1-c2;
	}
	while(c1 = c2);
}
int main(){
	strcmp("ndfcn","ndfsc");
}
