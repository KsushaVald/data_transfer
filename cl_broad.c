#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main(){
	int fd_socket;
        struct sockaddr_in s_addr;
        char buf[256];
	socklen_t len=sizeof(struct sockaddr);
        s_addr.sin_family=AF_INET;
        s_addr.sin_port=htons(7777);
        s_addr.sin_addr.s_addr=inet_addr("192.168.2.255");
        fd_socket=socket(AF_INET, SOCK_DGRAM,0);
	if(bind(fd_socket,(struct sockaddr*)&s_addr,sizeof(s_addr))==-1){
		perror("bind");
		exit(-1);
	}
       	recvfrom(fd_socket,buf,256,0,(struct sockaddr*)&s_addr,&len);
        printf("%s",buf);

}
