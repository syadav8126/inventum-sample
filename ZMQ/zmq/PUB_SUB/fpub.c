#include <zhelpers.h>
#include <zmq.h>
#include <unistd.h>

int main (void)
{
	char *p, buff[250];
	FILE *fp = fopen("dumpfile.json","r");
	void *context = zmq_ctx_new ();
    void *publisher = zmq_socket (context, ZMQ_PUB);
    zmq_bind (publisher, "tcp://*:5563");
        char str1[3]= "A", str2[3]="B", str3[3]="C";
    while (1) {
	p = fgets(buff, 10,fp );
	while(p!='\0'){
	printf("%s",buff);
	zmq_send(publisher,str1 ,strlen(str1),ZMQ_SNDMORE);
        s_send (publisher, buff);
	p = fgets(buff, 10, fp);
	}
        sleep (1);
    }
    zmq_close (publisher);
    zmq_ctx_destroy (context);
    return 0;
}                      
