#include <stdio.h>
void c(){
	printf("3:%p\n",__builtin_frame_address(0));  // will return the starting pointer of the stack allocated to this process
	printf("3:%p\n",__builtin_return_address(0));
}
void b(){
	printf("2:%p\n",__builtin_frame_address(0));  // will return the starting pointer of the stack allocated to this process
	printf("2:%p\n",__builtin_return_address(0));
	 c();
}
void a(){
	printf("4:%p\n",__builtin_frame_address(0));  // will return the starting pointer of the stack allocated to this process
	printf("1:%p\n",__builtin_return_address(0));
	b();
}
int main(){
	printf("4:%p\n",__builtin_frame_address(0));  // will return the starting pointer of the stack allocated to this process
	a();	
	printf("4:%p\n",__builtin_frame_address(0));  // will return the starting pointer of the stack allocated to this process
	printf("5:%p\n",__builtin_return_address(0));

}
