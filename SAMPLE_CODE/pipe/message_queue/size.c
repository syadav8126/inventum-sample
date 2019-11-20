#include <stdio.h>
struct adrak{
	int a;
	char b;
};
int main(){
	int size;
	size = (sizeof((struct adrak *)0x0)->a);
	printf("%d\n",size);
}
