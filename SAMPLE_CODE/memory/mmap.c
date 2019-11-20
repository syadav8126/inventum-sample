#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
       #include <sys/stat.h>
       #include <fcntl.h>

int main()
{
	int fd, pagesize;
	char *data;
	fd = open("a.out", O_RDONLY);
	pagesize = getpagesize();
	data = mmap((caddr_t)0, pagesize, PROT_READ , MAP_SHARED, fd,pagesize);
	printf (":::%s\n",data);
}
