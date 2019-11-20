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
int main(){
	int port = 65535;
	struct sockaddr_in addr;
	char buffer[1024] = {0};
	char *buf;
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);
	buf = malloc (1000);
	strcpy(buf,"stana");
	while(1){
		connect(sockfd, (struct sockaddr *)&addr, sizeof(addr) );
//		gets(buf);
		send(sockfd , buf , strlen(buf) , 0 );
		read( sockfd , buffer, 1024); 
//		memset(buffer,'\0',1024);
		close(sockfd);
	}


}
