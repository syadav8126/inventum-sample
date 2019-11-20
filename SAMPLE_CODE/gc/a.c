#include <stdio.h>
#include <pthread.h>
int a = 0;
void *lol()
{
	a = 1;
}
int main()
{
	pthread_t pid;
	pthread_create(&pid,NULL,&lol,NULL);
	pthread_detach(pid);
	if (a != 1) {
		while(a !=1)
		printf("a is 0\n");
	}
	if (a==1)
		printf("a is now 1\n");
	while(1);
	
}
