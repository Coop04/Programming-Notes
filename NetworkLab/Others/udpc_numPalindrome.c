#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

main() {
    struct sockaddr_in server;
    int lfd,n,num;
    char sbuf[100]="",rbuf[100]="";

    lfd=socket(AF_INET,SOCK_DGRAM,0);

    server.sin_family=AF_INET;
    server.sin_port=2000;
    server.sin_addr.s_addr=inet_addr("127.0.0.1");

    printf("Client ready...\n");

    n=sizeof(server);

    while(1) {
        printf("Client: ");
        scanf("%s",sbuf);
        sendto(lfd,sbuf,sizeof(sbuf),0,(struct sockaddr*)&server,n);
        if(strcmp(sbuf,"exit")==0) {
            break;
        }
        recvfrom(lfd,rbuf,sizeof(rbuf),0,(struct sockaddr*)&server,&n);
        printf("Server: %s\n",rbuf);
    }
    close(lfd);
}
