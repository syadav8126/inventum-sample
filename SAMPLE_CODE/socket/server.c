#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
      #include <arpa/inet.h>
       #include <sys/socket.h>
union {
                unsigned short value;
                unsigned char byte[2];
                struct {
                        unsigned short one   : 1;
                        unsigned short two   : 2;
                        unsigned short three : 3;
                        unsigned short four  : 4;
                        unsigned short five  : 5;
                } field;
        } u;

int main(){
	int domain, back = 10, val;
	struct sockaddr_in addr ;
	int port = 65535,new;
	int addrlen = sizeof(addr);
	char buffer[1024] ={0};
	void *bufff;
	int sockfd = socket(AF_INET, SOCK_STREAM,0);
        u.field.one   = 1;
        u.field.two   = 2;
        u.field.three = 3;
        u.field.four  = 4;
        u.field.five  = 5;
	int aa;
	int *a;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = htons (port); 
	bind (sockfd, (struct sockaddr  *) &addr, sizeof(addr));
	listen (sockfd, back);
//	while(1){
	new = accept (sockfd, (struct sockaddr *)&addr, (socklen_t *)&addrlen);
//	if (new){
	read (new, buffer, 1024);
	printf("%s\n",buffer);
	aa = 1;
	a =&aa;
	//bufff = (void *)a;
	//send(new,(void *) (a), 4, 0);
	//aa >>= 1;
	//bufff = (void *)a;
	send(new,(void *) (aa>>1), 4, 0);
//	send(new, "hello from sever", 16, 0);
//}
//}
}
