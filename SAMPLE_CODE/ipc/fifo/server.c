#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>

	int fd;
void love_handle()
{
	close(fd);
	exit (1);
}

int main()
{
	const char* path="/tmp/adrak";
	char *buf = "123456";
	char *buf1 = malloc(5);
	signal (SIGINT, love_handle);
	mkfifo(path, 0666);
	fd = open(path, O_RDWR);
	if (fd < 0)
		printf("Unable to write\n");
	while(1)
	{
		if (write (fd, (void *)buf, 5)<0)
			printf("Unable to write \n");
		read(fd,(void *)buf1,5);
		printf("%s\n",buf1);
	}
}
