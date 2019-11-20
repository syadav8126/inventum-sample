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
const char *stana = "/tmp/stana";
const char *taylor = "/tmp/taylor";

void *write_taylor(){
	int fd;
	char buf[1000];
	while(1){
	fd = open(taylor, O_WRONLY);
	fgets(buf, 1000, stdin);
	write(fd, buf, strlen(buf)+1);
	close(fd);
	}
}

void *read_stana(){
	char buf[1000];
	int fd;
	while(1){
	fd = open(stana, O_RDONLY);
	read(fd, buf, 1000);
	printf("Stana: %s\n",buf);
	close(fd);
	}
}
int main()
{
	pthread_t pid1, pid2;
        if (!mkfifo(stana, 0666)){printf("Error in Creating pipe stana\n");};
        if (!mkfifo(taylor, 0666)){printf("Error in Creating pipe taylor\n");};
	pthread_create(&pid1, NULL, (void *)write_taylor, NULL);
	pthread_create(&pid2, NULL, (void *)read_stana, NULL);
	while(1){};
}
