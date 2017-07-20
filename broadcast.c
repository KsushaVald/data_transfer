#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main(){
 	int fd_socket; int flag=1;
	struct sockaddr_in my_addr, client;
	socklen_t len=sizeof(struct sockaddr);
	char buf[256];

	my_addr.sin_family=AF_INET;
        my_addr.sin_port=htons(7777);
        my_addr.sin_addr.s_addr=inet_addr("192.168.2.255");
        fd_socket=socket(AF_INET, SOCK_DGRAM,0);
	setsockopt(fd_socket, SOL_SOCKET,SO_BROADCAST,&flag,sizeof(flag));
	strcpy(buf,"hello\n\0");
	sendto(fd_socket, buf, sizeof(buf), 0,(struct sockaddr*)&my_addr,len);
}
