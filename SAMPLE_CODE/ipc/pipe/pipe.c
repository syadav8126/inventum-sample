#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
int main()
{
	int fd[2];
	char *buf="Writing something";
	char *rbuf;
	if (pipe(fd)<0 )
	{
		printf("Unable to create pipe\n");
		return -1;
	}
	int pid = fork();
	if (pid < 0)
		printf("Unable to fork\n");
	else if (pid > 0 ){
		while(1)
		{
			int ret = write(fd[1],(void *)buf,strlen(buf));
			if(write(fd[1],(void *)buf,strlen(buf))<0)
			{
				printf("Error in writing to buf\n");
				return -1;
			}
		}
	}
	else if(pid ==0 )
	{
		printf("pid:%d\n",getpid());
		printf("ppid:%d\n",getppid());
		rbuf = malloc (strlen(buf));
			fcntl(fd[0], F_SETFL, O_NONBLOCK); //Making read command as NONBLOCKING
		while(1)
		{
			int ret = read(fd[0],(void *) rbuf, strlen(buf));
			if(read(fd[0],(void *) rbuf, strlen(buf))<0)
			{
				printf("Unable to read\n");
			}
			printf("child reading:%s\n",rbuf);
		}
	}
	free(rbuf);
}
