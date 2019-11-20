#include <stdio.h> 
void add(int a, int b) 
{ 
	printf("Addition is %d\n", a+b); 
} 
void sub(int a, int b) 
{ 
	printf("Subtraction is %d\n", a-b); 
} 
void multi(int a, int b) 
{ 
	printf("Multiplication is %d\n", a*b); 
} 
int main() 
{
	void (*fun_ptr_arr[])(int,int) = {add, sub, multi};
	unsigned int ch, a = 15, b = 10; 

	for (ch=0;ch<3;ch++)
	(*fun_ptr_arr[ch])(a, b); 

	return 0; 
} 

