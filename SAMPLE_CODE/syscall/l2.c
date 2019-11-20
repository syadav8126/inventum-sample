#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <unistd.h>
int main(){
	int a = getpid();
	int c = fork();
	printf("%d %d\n",a,c);
}
