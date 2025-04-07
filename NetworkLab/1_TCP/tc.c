#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <arpa/inet.h>

main() {
    struct sockaddr_in server;
    int lfd;
    char sbuf[100]="", rbuf[100]="";

    lfd = socket(AF_INET,SOCK_STREAM,0);

    server.sin_family = AF_INET;
    server.sin_port = 2000;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    printf("Client ready\n");

    connect(lfd,(struct sockaddr *)&server,sizeof(server));

    printf("Client:");
    gets(sbuf);
    send(lfd,sbuf,sizeof(sbuf),0);
    recv(lfd,rbuf,sizeof(rbuf),0);
    printf("Server:%s",rbuf);

    close(lfd);
}