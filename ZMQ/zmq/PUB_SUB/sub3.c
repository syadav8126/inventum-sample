#include <zhelpers.h>

int main (void)
{
    void *context = zmq_ctx_new ();
    void *subscriber = zmq_socket (context, ZMQ_SUB);
    zmq_connect (subscriber, "tcp://localhost:5563");
    zmq_setsockopt (subscriber, ZMQ_SUBSCRIBE, "C", 1);

    while (1) {
        char *address = s_recv (subscriber);
        char *contents = s_recv (subscriber);
        printf (" %s\n", contents);
        free (address);
        free (contents);
    }
    zmq_close (subscriber);
    zmq_ctx_destroy (context);
    return 0;
}

