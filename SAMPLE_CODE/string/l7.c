#include <stdio.h>
extern int  etext,edata,end;
int main(){
	int a = -10;
	printf("%d\n",end);
//	printf("%d\n",a++);
//	printf("%d\n",++a);
	printf("%d\n",-(a--));
//	printf("%d\n",+++a);
	
}
