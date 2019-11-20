#include <stdio.h>
#include <string.h>

struct {
   unsigned int loda;
   unsigned int lehsn;
} status1;

struct {
   unsigned int loda : 1;
   unsigned int lehsn : 1;
} status2;
 
int main( ) {
   printf( "Memory size occupied by status1 : %ld\n", sizeof(status1));
   printf( "Memory size occupied by status2 : %ld\n", sizeof(status2));
	status2.loda = 7;
	printf("%d\n",status2.loda);
   return 0;
}
