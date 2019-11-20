#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int swab1 (const void *bfrom, void *bto, ssize_t n)
{
		const char *from = (const char *) bfrom;
		char *to = (char *) bto;

		n &= ~((ssize_t) 1);
		while (n > 1)
		{
				const char b0 = from[--n], b1 = from[--n];
				to[n] = b0;
				printf("%c",to[n]);
				to[n + 1] = b1;
				printf("%c",to[n+1]);
		}
}
int main(){
	const char *pablo="th  is";
	char  *ansh;
	ansh = (char * )malloc (25);
	swab1( pablo, ansh, strlen (pablo) );
	printf("  %s\n",ansh);
}
