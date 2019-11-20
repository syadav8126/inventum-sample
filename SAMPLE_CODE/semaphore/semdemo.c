#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/sem.h>
       #include <sys/types.h>
       #include <sys/ipc.h>
       #include <sys/sem.h>

/*
defined in sys/sem.h
struct sembuf
{
  unsigned short int sem_num;                            
  short int sem_op;                                      
  short int sem_flg;         
};
*/
union semun {    
		int val;	
		struct semid_ds *buf;    
		ushort *array;
};

int initsem(key_t key, int nsems){
	int semid;
	union semun arg;
	struct sembuf sb;

	semid = semget(key, nsems, IPC_CREAT | IPC_EXCL | 0666);
	if (semid >= 0){
		sb.sem_op = 1;
		sb.sem_flg = 0;		
		arg.val = 1;
		printf("Press return \n");
		getchar();
		for (sb.sem_num = 0; sb.sem_num < nsems; sb.sem_num++){
			if (semop (semid, &sb, 1)==-1){
				int err = 1;
				semctl(semid, 0, IPC_RMID); /* clean up */                
				return -1;
			}
		}	
	}
}

int main()
{
	key_t key;
	int semid;
	struct sembuf sb;
	key = ftok("semdemo.c", 'J');
	if (key == -1) perror("Error in ftok\n");
	if (initsem (key, 1) == -1) 
		perror ("Error in initsem\n");
	printf("Pess to lock semaphore\n");
	getchar();
	semop(semid, &sb, 1);
	printf("Semaphore is locked \n");
	sb.sem_op = 1; /* free resource */    
	if (semop(semid, &sb, 1) == -1) {
		perror("semop");
		exit(1);
	}
	printf("Unlocked\n");   


}
