#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 10

void* thread(void* idp);

int threads_running = 0;
pthread_mutex_t* mutex;
pthread_cond_t* cond;

int main(int args, char **argv)
{
    pthread_mutex_t mutex_var;
    pthread_cond_t cond_var;

    mutex = &mutex_var;
    cond = &cond_var;

    pthread_mutex_init(mutex, NULL); 
    pthread_cond_init(cond, NULL);

    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++)
    {
        printf("Creating Thread %d....\n", i);

        int* id = malloc(sizeof(int));
        *id = i;

        if(0 != pthread_create(&threads[i], NULL, thread, (void *) id))
        {
            perror("Error while creating the threads");
            exit(1);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) 
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}


void* thread(void* idp)
{   
    int* id = (int*) idp;

    while (1)
    {
        sleep(*id); // Thread work

        pthread_mutex_lock(mutex);
            threads_running++;
        pthread_mutex_unlock(mutex);
        pthread_cond_broadcast(cond);

        printf("Thread %d WAIT\n", *id);
        fflush(stdout);

        // Let threads synchronize

        pthread_mutex_lock(mutex);
            while(threads_running != 0 && threads_running != NUM_THREADS)
            {
                pthread_cond_wait(cond, mutex);
            }
        pthread_mutex_unlock(mutex);    

        printf("Thread %d WAKEUP\n", *id);
        fflush(stdout);

        // and continue

        pthread_mutex_lock(mutex);
            threads_running = 0;
        pthread_mutex_unlock(mutex);
    }
}
