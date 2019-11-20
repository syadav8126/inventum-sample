#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>

int main()
{
	key_t key;
	char *path="/tmper";
	key = ftok(path, 55);
	int shmid = shmget(0x12345, 1024, 0666 | IPC_CREAT);
	char *buf = shmat (shmid, (void *)0, 0);
	while(1)
	{
		while(strcmp(buf,"lehsun"));
		printf("got l2: %s\n",buf);
		getchar();
		printf("feed l2:");
		scanf("%s\n",buf);
		getchar();
	}
}
