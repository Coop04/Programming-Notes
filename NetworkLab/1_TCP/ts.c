#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

main() {
    struct sockaddr_in server,client;
    int lfd,confd,n;
    char sbuf[100]="",rbuf[100]="";

    lfd = socket(AF_INET,SOCK_STREAM,0);

    server.sin_family = AF_INET;
    server.sin_port = 2000;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind(lfd,(struct sockaddr *)&server, sizeof(server));
    listen(lfd,1);

    printf("Server ready\n");
    n = sizeof(client);
    confd = accept(lfd,(struct sockaddr *)&client, &n);
    
    recv(confd,rbuf,sizeof(rbuf),0);
    printf("Client:%s\n",rbuf);
    printf("Server:");
    gets(sbuf);
    send(confd,sbuf,sizeof(sbuf),0);
    close(confd);
    close(lfd);
    
}