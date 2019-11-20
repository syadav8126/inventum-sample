#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include <pthread.h>    /* required for pthreads */
#include <semaphore.h>  /* required for semaphores */
void *thread_func(void * arg);
typedef struct thread_data {
	int in;	/* used as an input value */
	int out;	/* used as an output value */
} thread_data_t;
static sem_t count_sem;
int quit = 0;
int main(int argc, char *argv[]){
	pthread_t tid[2];
	thread_data_t a[2];
	thread_data_t* b[2] = {NULL, NULL};
	int ret, v;
	a[0].in = 2; a[0].out = 0;
	a[1].in = 4; a[1].out = 0;
	if (sem_init(&count_sem, 0, 1))
		printf("semaphore failed\n");
	if (argc > 1)
		quit = atoi(argv[1]);
	pthread_create(&tid[0], NULL, thread_func, (void *)(&a[0]));
	pthread_create(&tid[1], NULL, thread_func, (void *)(&a[1]));
	printf("main: process id %d, thread id = %d\n",(int) getpid(),(int) pthread_self());
	printf("main: tid[0] = %d, tid[1] = %d\n", tid[0], tid[1]);
	printf("main: &a[0] = 0x%08lx, &a[1] = 0x%08lx\n", &a[0], &a[1]);
	printf("main:  b[0] = 0x%08lx,  b[1] = 0x%08lx\n",  b[0],  b[1]);
	printf("main: a[0].in  = %ld, a[1].in  = %ld\n", a[0].in,  a[1].in);
	printf("main: a[0].out = %ld, a[1].out = %ld\n", a[0].out, a[1].out);

	if (sem_getvalue(&count_sem, &v))
		printf("error in getting value\n");
	else 
		printf("count semvlaue: %d\n",v);
	if (quit == 1) pthread_exit(NULL);
	if (quit == 2) exit(0);
	if (quit == 3) pthread_cancel(tid[1]);
	pthread_join(tid[0], (void **)&b[0]);

	if ((ret = pthread_join(tid[1], (void **)&b[1])) != 0){
		printf("main: pthread_join(tid[1],...) failed on return, %s\n", strerror(ret));
		printf("main: b[1] will be reset from 0x%08x to 0x%08x\n", b[1], NULL);
		b[1] = NULL;
	}
	else if (b[1] != &a[1])
	{
		printf("main: pthread_join(tid[1],...) failed on address, %s\n", strerror(-(int)b[1]));
		printf("main: b[1] will be reset from 0x%08x to 0x%08x\n", b[1], NULL);
		b[1] = NULL;
	}
	printf("\n");
	printf("main: process id %ld, thread id = %ld\n", getpid(), pthread_self());
	printf("main: tid[0] = %ld, tid[1] = %d\n", tid[0], tid[1]);
	printf("main: &a[0] = 0x%08lx, &a[1] = 0x%08lx\n", &a[0], &a[1]);
	printf("main:  b[0] = 0x%08lx,  b[1] = 0x%08lx\n",  b[0],  b[1]);
	printf("main: a[0].in   = %ld, a[1].in   = %ld\n", a[0].in,  a[1].in);
	printf("main: a[0].out  = %ld, a[1].out  = %ld\n", a[0].out, a[1].out);
	if (b[0] == NULL && b[1] == NULL) {
		printf("main: b[0] is NULL, b[1] is NULL\n");
	} else if (b[0] == NULL) {
		printf("main: b[0] is NULL, b[1]->in = %d, b[1]->out = %d\n", b[1]->in, b[1]->out);
	} else if (b[1] == NULL) {
		printf("main: b[0]->in = %d, b[0]->out = %d, b[1] is NULL\n", b[0]->in, b[0]->out);
	} else {
		printf("main: b[0]->in  = %d, b[1]->in  = %d\n", b[0]->in,  b[1]->in);
		printf("main: b[0]->out = %d, b[1]->out = %d\n", b[0]->out, b[1]->out);
	}

	if (quit == 3 && b[1] != NULL && b[1]->out < 0)
		printf("main: thread %d returned b[1]->out = %d\n", tid[1], b[1]->out);

	if (quit == 6) pthread_exit(NULL);
	if (quit == 7) exit(0);

	return 0;
}

void * thread_func(void * arg)
{
	static int count = 0;
	int s = 0, t, v;
	thread_data_t *p = (thread_data_t *)arg;
	sem_wait(&count_sem);         /* start of critical section */
	count++;
	sem_post(&count_sem);         /* end of critical section */
	s++;
	printf("thread: process id %d, thread id = %d, p->in = %d, count = %d, s = %d\n",
			getpid(), pthread_self(), p->in, count, s);
	if (sem_getvalue(&count_sem, &v) == -1)
	{ printf("sem_getvalue: failed: %s\n", strerror(errno)); }
	else
	{ printf("thread: count_sem value = %d\n", v); }
	sleep(p->in);

	sem_wait(&count_sem);
	count++; t = count;
	sem_post(&count_sem);
	s++;

	printf("thread: process id %d, thread id = %d, arg = %d, count = %d, s = %d\n",
			getpid(), pthread_self(), p->in, t, s);

	if (quit == 4)
	{
		p->out = -(int)pthread_self();
		pthread_exit(arg);
	}

	if (quit == 5) exit(0);

	p->out = (int)pthread_self();
	return arg;
}


