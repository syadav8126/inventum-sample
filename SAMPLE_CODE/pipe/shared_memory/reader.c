#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <stdio.h> 
int main() 
{ 
	key_t key = ftok("shmfile",65); 
	int shmid = shmget(key,1024,0666|IPC_CREAT); 
	
	while(1){
	char *str = (char*) shmat(shmid,(void*)0,0); 
	printf("Data read from memory: %s\n",str); 
	shmdt(str); 
	}
	return 0; 
} 

