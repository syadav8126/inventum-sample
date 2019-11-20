#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
struct msgbuf{
	long  mtype;    //first variable must be long
	char mtext[1];
};
int main()
{
	key_t key;
	int msgflg;
	int msqid;
	int msend;
	struct msgbuf *buf;
	key = ftok("/tmp/stana", 'b');
	msqid = msgget( key, 0666 | IPC_CREAT);  // create a queue returing msqid as the queue id
	msend = msgsnd(msqid, buf, 1, 0);
/* In case of receive 
	int mrecv = msgrcv (msqid, buf, 1, 2, 0);
*/

/* Destroying a message queue
	int  mdes = msgctl (msqid, IPC_RMID, NULL);
*/

}
