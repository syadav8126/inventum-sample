#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
int main()
{
	union sem{
		               int val;
               struct semid_ds *buf;
               ushort *array;
		}arg;
	key_t key;
	char *path="adrak";
	key = ftok (path, 55);
	struct sembuf *sops;
	int semid;
	int nsops;
	int i, j;
	if (semid = semget(key, 1, IPC_CREAT | 0666)<0)
		printf("Unable to get the semget\n");

	int pid = fork();
	if (pid == 0)
	{
		nsops = 2;
		sops[0].sem_num = 0;
		sops[0].sem_op = 0;
		sops[0].sem_flg = SEM_UNDO;
		sops[1].sem_num = 0;
		sops[1].sem_op = 0;
		sops[1].sem_flg = SEM_UNDO;
		if ((j = semop(semid, semop, nsops)) == -1)
			printf("Semop failed \n");
		else 
			(void) fprintf(stderr, "\tsemop: semop returned %d\n", j);
		sleep (3);
		nsops = 1;
		
		sops[1].sem_num = 0;
		sops[1].sem_op = -1;
		sops[1].sem_flg = SEM_UNDO | IPC_NOWAIT;
		

	}
	
}
