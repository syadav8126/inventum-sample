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
	char *buf = malloc(5);
	char *buf1 = "adrak";
	const char* path = "/tmp/adrak";
	 signal (SIGINT, love_handle);
	fd = open(path, O_RDWR);
	if (fd < 0)
		printf("Unable to open\n");
	fcntl(fd, F_SETFL, O_NONBLOCK);
	while(1){
		memset (buf, 0 , 5);
		int ret = read(fd, (void *)buf, 12);
		write(fd,(void *)buf1,5);
		printf("ret %d, %s\n",ret, buf);
	}
}

