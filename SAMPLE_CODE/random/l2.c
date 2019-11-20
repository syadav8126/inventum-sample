
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
int main(int argc,char **argv)
{
	link("a");
	printf("safdf\n");
	free(NULL);
	return 0;
}
