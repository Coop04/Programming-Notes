#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

void main() {
    struct sockaddr_in server;
    int lfd;
    char rbuf[100]="", sbuf[100]="";

    lfd = socket(AF_INET,SOCK_STREAM,0);
    
    server.sin_family = AF_INET;
    server.sin_port = 1002;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    printf("\nClient ready....\n");

    connect(lfd,(struct sockaddr *)&server, sizeof(server));

    while(1) {
        printf("Client: ");
        gets(sbuf);
        send(lfd,sbuf,sizeof(sbuf),0);

        if(strcmp(sbuf,"exit")==0) {
            break;
        }
        recv(lfd, rbuf, sizeof(rbuf),0);
        printf("Server: %s\n",rbuf);
    }
    close(lfd);
}