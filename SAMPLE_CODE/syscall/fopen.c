#include<stdio.h> 
int main() 
{ 
	int i, n=2; 
	char str[50]; 

	//open file sample.txt in write mode 
	FILE *fptr = fopen("sample.txt", "a"); 
	for (i=0; i<n; i++) 
	{ 
		puts("Enter a name"); 
		gets(str); 
		fprintf(fptr,"%d.%s\n", i, str); 
	} 
	fclose(fptr); 

	return 0; 
} 
