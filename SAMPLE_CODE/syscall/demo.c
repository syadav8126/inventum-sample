#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main(){
	int fd = open ("//etc/password", O_RDONLY);
	close (fd);
	return 0;
}
