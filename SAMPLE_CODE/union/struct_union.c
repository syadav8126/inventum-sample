#include <stdio.h>
#include <stdlib.h>
struct taylor{
	int a;
};
union swift{
	unsigned char a;
	unsigned char wa;
	unsigned char aw;
	unsigned char ww;
};
int main(){
	printf("size of struct : %ld\n",sizeof(struct taylor));
	printf("size of unoin  : %ld\n",sizeof(union swift));
	union swift *degi;
	struct taylor *yeb;
	degi = malloc(4);
	yeb = malloc(4);
	yeb->a = 255;
	printf("%d\n",yeb->a);
	degi = (union swift *)yeb;
	printf("%d\n",degi->a);
	printf("%d\n",degi->wa);
	printf("%d\n",degi->aw);
	printf("%d\n",degi->ww);
}
