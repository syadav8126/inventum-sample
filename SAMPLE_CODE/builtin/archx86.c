#include <stdio.h>
void main(){

	__builtin_cpu_init();
	if(__builtin_cpu_supports ("ssse3"))
		printf("yes");
	else
		printf("1yes");
	if(__builtin_cpu_is ("amd"))
		printf("yes");
	else
		printf("1yes");

	printf("%s",__builtin_cpu());
}
		
