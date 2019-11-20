#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	void *stana ,*katic;
	char *jlo;
int do_susu(int i){
		jlo = katic - i - 20000;
		return 1;
}
int main(){
	int i=32;
	stana = malloc (10);
	katic = malloc (10);
	strcpy(stana,"jo bole so nihal,ho\n");
	printf ("stana : %p\n",stana);
	for (i=10;i>7;i++)
	{
		if(do_susu(i) == 1)
		printf ("%p: ",jlo);
		printf ("%c\n",*jlo);
	}



}
