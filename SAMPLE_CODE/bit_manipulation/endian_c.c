#include <stdio.h> 
void show_mem_rep(char *start, int n) 
{ 
	int i; 
	for (i = 0; i < n; i++) 
		printf("%x ", start[i]); 
	printf("\n"); 
} 
void check_endian (){
	int a = 1;
	printf("%p\n",&a);
	char *c =(char* )&a;
	printf("%p\n",c);
}
void problem(){
	unsigned char arr[2] = {0x01,0x02}; 
	unsigned short int x = *(unsigned short int *) arr; 
	printf("%x", x); 
}
int main() 
{ 
	int i = 0x01234567; 
	void * a = "asf";
	show_mem_rep((void *)&i, sizeof(i)); 
//	check_endian();
//	problem();
	return 0; 
} 
