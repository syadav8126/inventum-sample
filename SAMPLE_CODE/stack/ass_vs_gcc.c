#include <stdio.h>
unsigned long get_sp(void){
	asm("movl %esp,%ebx");
}
unsigned long get_bp(void){
	__asm__("movl %ebp,%ebx");
}
void tata( int a ){
	printf("=========tata=======%d\n",a);
	printf("inside sp : %x\n",get_sp);
	printf("inside bp : %x\n",get_bp);
	printf("frame     :%p\n",__builtin_frame_address(0));       //gives real physical address
	printf("stack     :%p\n",__builtin_return_address(0));
}

void pablo( int a ){
	printf("=========pablo=======%d\n",a);
	printf("inside sp : %x\n",get_sp);
	printf("inside bp : %x\n",get_bp);
	printf("frame     :%p\n",__builtin_frame_address(0));
	printf("stack     :%p\n",__builtin_return_address(0));
	tata(a);
}

int main(){
	printf("=========before-ptr===== \n");
	printf("before ptr: %x\n",get_sp);
	printf("before ptr: %x\n",get_bp);
	printf("frame     :%p\n",__builtin_frame_address(0));
	printf("stack     :%p\n",__builtin_return_address(0));
	int *b = NULL;
	int a=0;
	printf("=========after -ptr===== \n");
	printf("before ptr: %x\n",get_sp);
	printf("outside bp: %x\n",get_bp);
	printf("main frame:%p\n",__builtin_frame_address(0));
	printf("stack     :%p\n",__builtin_return_address(0));
	pablo(a);
}
