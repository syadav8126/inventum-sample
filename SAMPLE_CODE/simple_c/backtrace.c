#include <stdio.h>
int main(){
	printf("%p\n",__builtin_frame_address(0)); // base address of stack in this process
	printf("%p\n",__builtin_return_address(0)); // frame address of stack in this process
	printf("%p\n",({ char __csf; &__csf; }));  // current frame pointer
}
