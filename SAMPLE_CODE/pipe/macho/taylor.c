//client 2 : taylor
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
const char *stana = "/tmp/stan";
union father{
        long int add;
        char buf[8];

};
union father son;

int i=0;
void *read_stana(){
	char buf[1000];
	void *l;
	int fd;
	long int k;
	fd = open(stana, O_RDONLY);
	while(1){
	read(fd, son.buf, 8);
	printf("%d recv : %ld\n",i,son.add);
	i++;
	if (i >=20)
		printf("recv : %c\n",**(char **)son.buf);
	}
	close(fd);
}
int main()
{
	
        if (!mkfifo(stana, 0666)){printf("Error in Creating pipe stana\n");};
	read_stana();
}
