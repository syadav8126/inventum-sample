#include <stdio.h>
int i=0;
void a(){

	if (i==1) {break;}
	i++;
	a();
}
int main(){
	a();
}
