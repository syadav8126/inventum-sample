#include <stdio.h>
unsigned long get_sp(void) {
   __asm__("movl %esp,%eax");
   }
void call(){
	char arr[2];
	gets(arr);
	printf("arr :%s\n",arr);
     printf("sp:0x%x\n", get_sp());

}
int main(){
     printf("sp:0x%x\n", get_sp());
	call();
     printf("sp:0x%x\n", get_sp());
	}
