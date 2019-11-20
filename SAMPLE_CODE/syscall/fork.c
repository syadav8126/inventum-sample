#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define SHELL "/bin/sh"

int
my_system (const char *command)
{
		int status;
		pid_t pid;


		pid = fork ();
		if (pid == 0)
		{
				execl (SHELL, SHELL, "-c", command, NULL);
				_exit (EXIT_FAILURE);
		}
		else if (pid < 0)
				/* The fork failed.  Report failure.  */
				status = -1;
		else
				/* This is the parent process.  Wait for the child to complete.  */
				if (waitpid (pid, &status, 0) != pid)
						status = -1;
		return status;
}
int main(){
	my_system("ls");
}
