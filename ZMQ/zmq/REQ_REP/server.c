#include <zmq.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>

int main (void)
{
    //  Socket to talk to clients
    void *context = zmq_ctx_new ();
    void *responder = zmq_socket (context, ZMQ_REP);
    int rc = zmq_bind (responder, "tcp://*:5555");
    assert (rc == 0);
    char buff[4096];
    while (1) {
	FILE *fp;
	char *p;
	fp = fopen("dumpfile.json","r");
	p = fgets(buff,4096,fp);
        char buffer [10];
	while(p!='\0'){
        zmq_recv (responder, buffer, 0, 0);
        zmq_send (responder,buff, 4096, 0);
	printf("sent : %s",buff);
	fgets(buff,4096,fp);
	}
}
    return 0;
}
