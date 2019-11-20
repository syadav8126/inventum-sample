#include <stdio.h> 
typedef struct structa_tag 
{ 
	char    c; 
	short int  s; 
} structa_t; 

typedef struct structb_tag 
{ 
	double  s; 
	char    c; 
	int     i; 
} structb_t; 

typedef struct structc_tag 
{ 
	char    c; 
	double   d; 
	int 	 s; 
} structc_t; 

typedef struct structd_tag 
{ 
	double   d; 
	int 	 s; 
	char    c; 
} structd_t; 

int main() 
{ 
	printf("sizeof(structa_t) = %ld\n", (long int)sizeof(structa_t)); 
	printf("sizeof(structb_t) = %ld\n", (long int)sizeof(structb_t)); 
	printf("sizeof(structc_t) = %ld\n", (long int)sizeof(structc_t)); 
	printf("sizeof(structd_t) = %ld\n", (long int)sizeof(structd_t)); 

	return 0; 
} 

