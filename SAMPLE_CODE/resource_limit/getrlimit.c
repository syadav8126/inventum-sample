#include <sys/resource.h> 
#include <sys/time.h> 
#include <unistd.h> 
#include<stdio.h> 

int main () 
{ 
		struct rlimit rl; 
		getrlimit (RLIMIT_CPU, &rl); 
		printf("\n Default value is : %lld\n", (long long int)rl.rlim_cur); 
		rl.rlim_cur = 2 ; 
		setrlimit (RLIMIT_CPU, &rl); 
		getrlimit (RLIMIT_CPU, &rl); 
		printf("\n Default value now is : %lld\n", (long long int)rl.rlim_cur); 
		while (1); 

		return 0; 
}
