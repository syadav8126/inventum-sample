#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msgbuf {
	long mtype;
	char mtext[80];
};

int main()
{
	key_t key;
	int msgid;
	char *path = "/tmp/adrak";
	struct 	msgbuf buf;
	key = ftok(path, 33);
	strcpy(buf.mtext, "adrak-lehsun");
	buf.mtype =1;
	if (key<0)
		printf("Unable to create a unique key\n");
	msgid = msgget (key, IPC_CREAT|0666);
	if(msgid<0)
		printf("Unable to create message queue\n");
	while(1)
	{
	if (msgrcv(msgid, (void *) &buf, 10, 0,1)<0)
		printf("msgsnd error \n");
	printf("%s\n",buf.mtext);
	}
}
