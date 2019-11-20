#include <stdio.h>
#include <stdlib.h>
struct abc{

	int a;
	int b;
	int c;
};


int main(){
	struct abc *xyz;
	struct abc *xy;
	xyz=(struct abc *)malloc(sizeof(struct abc*));
//	xy=(struct abc *)malloc(sizeof(struct abc*));
	printf("%p    %p\n",xy,xy+1);
	
	free(xy);
//	xy = xyz;
	xyz->a  = 11;
	xyz->b  = 21;
	xyz->c  = 31;
	xy->a  = 11;
	xy->b  = 21;
	xy->c  = 31;

//	xy = xyz;
	xyz->a  = 41;
	printf("%p    %p\n",xyz,  xyz+1);
	printf("%p    %p\n",xy,xy+1);
	printf("a:%d\nb:%d\nc:%d\n",xy->a,xy->b,xy->c);
	printf("a:%d\nb:%d\nc:%d\n",xyz->a,xyz->b,xyz->c);
	free(xy);
//	printf("sizer of struct :%ld\n",sizeof(xyz));
}

