//#include <stdio.h>
extern int printf (const char *__restrict __format, ...);
int main(){
	int a=1;
	printf("%d\n",a);
	a = 3 & (1U << 1);
	printf("%d\n",a);
}
