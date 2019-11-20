// client 1: jenny, two fifo  will be created 
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
const char *stana = "/tmp/stan";
char *new="==============================";
union father{
	long int add;
	char buf[8];

};
union father son;
char a = 'r';

void *write_stana(){
	int fd;
	char buf[1000];
	fd = open(stana, O_WRONLY);
	write(fd,new, 30);
	while(1){
		fgets(buf, 100, stdin);
		write(fd,(void *)son.buf, 8);
		printf("%c\n",**(char **)son.buf);
	}
	close(fd);
}

int main()
{
	son.add = (long int)&a;
	printf("%ld\n",son.add);
	printf("%c\n",**(char **)son.buf);
	if (!mkfifo(stana, 0666)){printf("Error in Creating pipe stana\n");};
	write_stana();
}

