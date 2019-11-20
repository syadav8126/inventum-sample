#include <stdio.h> 
#include <sys/time.h>   
#include <sys/resource.h> 

///////////////////////////////////
// measure user and system time using the "getrusage" call. 
///////////////////////////////////
//struct rusage {
//   struct timeval ru_utime; /* user CPU time used */
//   struct timeval ru_stime; /* system CPU time used */
//   long   ru_maxrss;        /* maximum resident set size */
//   long   ru_ixrss;         /* integral shared memory size */
//   long   ru_idrss;         /* integral unshared data size */
//   long   ru_isrss;         /* integral unshared stack size */
//   long   ru_minflt;        /* page reclaims (soft page faults) */
//   long   ru_majflt;        /* page faults (hard page faults) */
//   long   ru_nswap;         /* swaps */
//   long   ru_inblock;       /* block input operations */
//   long   ru_oublock;       /* block output operations */
//   long   ru_msgsnd;        /* IPC messages sent */
//   long   ru_msgrcv;        /* IPC messages received */
//   long   ru_nsignals;      /* signals received */
//   long   ru_nvcsw;         /* voluntary context switches */
//   long   ru_nivcsw;        /* involuntary context switches */
//};

//struct timeval
//  {
//    long int tv_sec;       /* Seconds.  */
//    long int tv_usec;      /* Microseconds.  */
//  };


void main () { 
		struct rusage buf; 
		// chew up some CPU time
		int i,j; for (i=0,j=0; i<100000000; i++) { j+=i*i; }     
		getrusage(RUSAGE_SELF, &buf); 
		printf("user seconds without microseconds: %ld\n", buf.ru_utime.tv_sec); 
		printf("user microseconds: %ld\n", buf.ru_utime.tv_usec); 
		while(i<10){i++;}
		printf("integral shared meort size: %ld\n", buf.ru_isrss); 
		printf("total user seconds: %e\n", 
						(double) buf.ru_utime.tv_sec 
						+ (double) buf.ru_utime.tv_usec / (double) 1000000); 
} 
