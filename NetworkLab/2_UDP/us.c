#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>

main() {
    struct sockaddr_in server, client;
    int lfd, n;
    char sbuf[100]="", rbuf[100]="";

    lfd = socket(AF_INET,SOCK_DGRAM,0);

    server.sin_family = AF_INET;
    server.sin_port = 2000;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind(lfd, (struct sockaddr *)&server, sizeof(server));

    printf("Server Ready\n");

    n = sizeof(client);
    recvfrom(lfd, rbuf, sizeof(rbuf),0, (struct sockaddr *)&client, &n);
    printf("Client:%s",rbuf);
    printf("Server:");
    gets(sbuf);
    sendto(lfd, sbuf, sizeof(sbuf),0, (struct sockaddr *)&client, n);

    close(lfd);
}