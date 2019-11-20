#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main()
{
char *oldString = "Old String";
char *newString = strdup(oldString);
if(errno == ENOMEM)  // Fail!!!!
	printf("loaaaa");
free(newString);
 }     
