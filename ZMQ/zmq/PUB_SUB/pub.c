#include <zhelpers.h>
#include <zmq.h>
#include <unistd.h>

int main (void)
{
    //  Prepare our context and publisher
    void *context = zmq_ctx_new ();
    void *publisher = zmq_socket (context, ZMQ_PUB);
    zmq_bind (publisher, "tcp://*:5563");
	char str1[3]= "A", str2[3]="B", str3[3]="C";
    while (1) {
	zmq_send(publisher,str1 ,strlen(str1),ZMQ_SNDMORE);
        //s_sendmore (publisher, "A");
        s_send (publisher, "PUB to SUB A");
       // s_sendmore (publisher, "B");
	zmq_send(publisher,str2 ,strlen(str2),ZMQ_SNDMORE);
        s_send (publisher, "PUB to SUB B");
	//s_sendmore(publisher, "C");
	zmq_send(publisher,str3 ,strlen(str3),ZMQ_SNDMORE);
	s_send(publisher,"PUB to SUB C") ;
        sleep (1);
    }
    zmq_close (publisher);
    zmq_ctx_destroy (context);
    return 0;
}                      
