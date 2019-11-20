#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
void forkexample() 
{ 
} 
int main() 
{	// child process because return value zero 
	int pid = fork();
	if (pid == 0) 
		printf("Hello from Child!\n"); 

	// parent process because return value non-zero. 
	else if (pid > 0)
		printf("Hello from Parent!\n"); 
 
	return 0; 
} 

