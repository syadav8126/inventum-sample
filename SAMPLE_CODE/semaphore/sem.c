// C program to demonstrate working of Semaphores 
#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 

sem_t mutex; 

void* thread(void *arg) 
{ 
	//wait 
	sem_wait(&mutex); 
	printf("\nEntered tid: %ld\n",pthread_self()); 

	//signal 
	printf("\nExiting tid: %ld\n",pthread_self()); 
	sem_post(&mutex); 
} 

int main() 
{ 
	sem_init(&mutex, 0, 1); 
	pthread_t t1,t2; 
	pthread_create(&t1,NULL,thread,0x00); 
	pthread_create(&t2,NULL,thread,0x00); 
	pthread_join(t1,NULL); 
	pthread_join(t2,NULL); 
	sem_destroy(&mutex); 
	return 0; 
} 

