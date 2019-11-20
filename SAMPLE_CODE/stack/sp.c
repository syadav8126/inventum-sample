unsigned long get_sp(void) {
   __asm__("movl %esp,%eax");
   }
     
unsigned long get_bp(void) {
   __asm__("movl %ebp,%eax");
   }
void laura(){
	int a=0;
     printf("sp:0x%x\n", get_sp());
     printf("bp:0x%x\n", get_bp());
	int a1=1;
     printf("sp:0x%x\n", get_sp());
}
void main() {
     printf("sp:0x%x\n", get_sp());
     printf("bp:0x%x\n", get_bp());
   	int a; 
	a=10;
	laura();
}
