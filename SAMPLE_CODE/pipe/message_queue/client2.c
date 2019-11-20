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
int main(){
	struct msg buf;
	int key, qid;
	key = ftok ("client1.c", 'B');
	if (key == -1) perror ("Got No key\n");
	qid = msgget(key, 0666 );
	for (;;){
		msgrcv(qid, &buf, 200, 0, 0);
		printf("GOT: %s\n",buf.mtext);
}

}
