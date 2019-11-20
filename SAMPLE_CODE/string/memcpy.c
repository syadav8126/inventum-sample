#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define op_t  unsigned long int
#define OPSIZ (sizeof(op_t))
#define OP_T_THRES  16
typedef unsigned char byte;
void *
memcpy (void *dstpp, const void *srcpp, size_t len){
	unsigned long int dstp = (long int) dstpp;
	unsigned long int srcp = (long int) srcpp;
	printf("%ld:\n",srcp);
	printf("%ld:\n",dstp);
	do{               
		size_t __nbytes = (len);               
		while (__nbytes > 0)                  
		{
			byte __x = ((byte *) srcp)[0];              
			printf("%ld:%c\n",__nbytes,__x);
			srcp += 1;                    
			__nbytes -= 1;                 
			((byte *) dstp)[0] = __x;               
			dstp += 1;                    
		}                     
	} while (0);
	return dstpp;

}
int main(){
	void* s;
	void* e ;
	s = malloc (10);
	e = malloc (10);
	strcpy (s, "!!!!!!!!!!");
	printf("%s\n",(char *)s);
	memcpy(e,s,32);
	printf("%s\n",(char *)e);
}

