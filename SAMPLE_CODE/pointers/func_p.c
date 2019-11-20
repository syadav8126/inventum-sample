#include <stdio.h>
#include <stdlib.h>
int fp(int a){
	printf("value of a is :%d\n",a);
}
int fp1(int (*fnp)(int),int b){
	printf("value of b id :%d\n",b);
}
int main(){
	int (*func1)(int);
	//fp1((*fp)(10),12);
	func1 = malloc(100);
	func1 = fp;
	func1(19);	
}
