#include <sys/msg.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
struct msg{
	long mtype;
	char mtext[200];
};
int main()
{
	struct msg buf;
	int key, qid;
	if ((key = ftok ("client1.c", 'B')) == -1){
	perror ("ftok error\n");	
	exit(1);
	}
	printf("%x\n",key);
	qid = msgget (key, 0647 | IPC_CREAT);
	if (qid == -1){
	perror ("msgget\n");
	exit(1);
	}
	buf.mtype = 1;
	while (fgets(buf.mtext, 200, stdin) != NULL){
	int len = strlen (buf.mtext);	
	if (buf.mtext[len-1] == '\n')	buf.mtext[len-1] = '\0';
	int snd = msgsnd (qid, &buf, len+1, 0);
	if (snd == -1) perror("Send error\n");
	}
	msgctl(qid, IPC_RMID, NULL);
}
