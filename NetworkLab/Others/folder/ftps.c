#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define MAX 2049

main() {
    struct sockaddr_in server,client;
    int lfd,confd,n,byterecv;
    char buf[MAX]="";
    FILE *f;

    lfd = socket(AF_INET,SOCK_STREAM,0);

    server.sin_family=AF_INET;
    server.sin_port=2000;
    server.sin_addr.s_addr=inet_addr("127.0.0.1");

    bind(lfd,(struct sockaddr *)&server,sizeof(server));
    listen(lfd,1);

    printf("Server ready...\n");

    n=sizeof(client);
    confd=accept(lfd,(struct sockaddr*)&client,&n);

    while(1) {
        strcpy(buf,"");

        byterecv = recv(confd,buf,sizeof(buf)-1,0);
        if(byterecv<=0)
            break;
        if(strcmp(buf,"close")==0)
            break;
        buf[byterecv]='\0';

        f = fopen(buf,"r");
        if(f == NULL) {
            sprintf(buf,"@FILE NOT FOUND, PID: %d",getpid());
            send(confd,buf,strlen(buf),0);
        }
        else {
            if(f) {
                while(fread(buf,1,sizeof(buf),f)>0) {
                    send(confd,buf,strlen(buf),0);
                }
            }
            close(f);
        }

    }
    close(confd);
    close(lfd);
}
