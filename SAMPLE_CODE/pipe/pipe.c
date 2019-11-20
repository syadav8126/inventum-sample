#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
int  main(){
	int p[2];
	char *a;
	a = (char *)malloc(100);
	char buf[100];
	if (pipe(p) < 0)
		exit(1);
	while(1){
//	fgets(a, 1, stdin);
	scanf("%s",a);
//	*a = getchar();
	printf("strlen:%ld\n",strlen(a));
	write(p[1], a, strlen(a));
	read(p[0], buf, strlen(a));
	printf("%s\n", buf);
}}
