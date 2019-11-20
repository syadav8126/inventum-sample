#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>

int main()
{
	key_t key;
	char *path="/tm";
	key = ftok(path, 5);
	int shmid = shmget(0x12345, 1024, 0666 | IPC_CREAT);
	char *buf = shmat (shmid, (void *)0, 0);
	while(1)
	{
		printf("Feed l1:");
		scanf("%s",buf);
		while(strcmp(buf,"adrak"));
		printf("got l1:%s\n",buf);
		getchar();
	}
}
