#include <stdio.h>
#include <unistd.h>
#include <syslog.h>
int main()
{
	while(1)
	{
		syslog(LOG_NOTICE,"Hello this is log notice from nas\n");
		sleep(1);
	}
}
