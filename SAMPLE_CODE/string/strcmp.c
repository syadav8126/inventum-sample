#include <stdio.h>
#include <string.h>

int my_cmp (const char *p1, const char *p2){
	const unsigned char *s1 = (const unsigned char*)p1;
	const unsigned char *s2 = (const unsigned char*)p2;
	unsigned char c1,c2;
	do {
		c1 = *s1++;	
		c2 = *s2++;
		printf("%d:\n",c1);
		if (c1 == '\0')
		return c1 - c2;
	}
	while (c1 == c2);
	return (c1 - c2);
}

int main(){
	char *a = "abcd";
	char *b = "abcdd";
	printf("%d\n",my_cmp(a,b));


}
