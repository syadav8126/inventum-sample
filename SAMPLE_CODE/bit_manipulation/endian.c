#include <stdio.h>
#include <endian.h>

#if __BYTE_ORDER ==  __BIG_ENDIAN
	#define proof printf("Adrak\n");
	#define isbit(bit)  (1 << bit)

#else
	#define proof printf("Lehsun\n");
	#define isbit(bit)  ((bit) < 8 ? ((1 << (bit)) << 8) : ((1 << (bit)) >> 8))
#endif
int main(){
	printf ("byte order :: %d\n",__BYTE_ORDER);
	proof;	
}
