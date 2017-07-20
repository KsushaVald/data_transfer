#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main(){
        int fd_socket;
        struct sockaddr_in  my_addr;
        socklen_t len=sizeof(struct sockaddr);
        char buf[256]="k\0";
	struct  ip_mreq req;

	req.imr_multiaddr.s_addr=inet_addr("224.0.0.180");
	req.imr_interface.s_addr=htonl(INADDR_ANY);
        my_addr.sin_family=AF_INET;
        my_addr.sin_port=htons(23456);
        my_addr.sin_addr.s_addr=inet_addr("224.0.0.180");

        fd_socket=socket(AF_INET, SOCK_DGRAM,0);
	if(bind(fd_socket,(struct sockaddr*)&my_addr, sizeof(my_addr))==-1){
		perror("bind");
		exit(-1);
	}
        if(setsockopt(fd_socket,IPPROTO_IP,IP_ADD_MEMBERSHIP,&req,sizeof(req))==-1){
		perror("setsockopt");
		exit(-1);
	}
	recvfrom(fd_socket,&buf,sizeof(buf),0,(struct sockaddr*)&my_addr, &len);
	printf("%s",buf);
}
