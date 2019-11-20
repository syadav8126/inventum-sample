#include <stdio.h>
#include <stdlib.h>
struct stana{
	int a;
	int b;
	long int c;
};
int main(){
	struct stana *sb;
	sb = (struct stana*)malloc(sizeof(struct stana));
	sb->a=3;
	sb->b=6;
	sb->c=-9223372036854775807;
	printf("%p:",&sb->a); printf("%d\n",*(&sb->a));
	printf("%p:",&sb->a+1);	printf("%d\n",*(&sb->a+1));
	printf("%ld\n",sb->c);
	printf("%p:",&sb->a+2);	printf("%ld\n",*(&sb->a+2));
	printf("%p:",&sb->a+3);	printf("%d\n",*(&sb->a+3));
}
