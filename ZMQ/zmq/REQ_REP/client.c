#include <zmq.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main (void)
{
	FILE* fp;
	fp = fopen("ZMQ-recd","w+");
    printf ("Connecting to hello world server…\n");
    void *context = zmq_ctx_new ();
    void *requester = zmq_socket (context, ZMQ_REQ);
    zmq_connect (requester, "tcp://localhost:5555");
	char buff[190]="Hello";
    int request_nbr;
    for (request_nbr = 0; request_nbr != 346; request_nbr++) {
        char buffer [4096];
        zmq_send (requester, buff, 0, 0);
        zmq_recv (requester, buffer,4096 , 0);
	 printf ("  %s",buffer);
	fputs(buffer,fp);
    }
    zmq_close (requester);
    zmq_ctx_destroy (context);
    return 0;
}
