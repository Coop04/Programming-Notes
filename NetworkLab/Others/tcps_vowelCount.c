#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

void vcCount(char s[],char *result) {
    int v=0,c=0;
    for(int i = 0;i<strlen(s);i++) {
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') {
            v++;
        }
        else {
            c++;
        }
    }
    sprintf(result,"Vowels: %d\tConsonents: %d",v,c);
}

main() {
    struct sockaddr_in server, client;
    int lfd, confd, n;
    char rbuf[100]="", sbuf[100]="";

    lfd = socket(AF_INET,SOCK_STREAM,0);
    
    server.sin_family = AF_INET;
    server.sin_port = 2000;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind(lfd,(struct sockaddr*)&server, sizeof(server));
    listen(lfd,1);

    printf("\nServer is ready....\n");
    n = sizeof(client);
    confd = accept(lfd,(struct sockaddr *)&client, &n);

    while(1) {
        recv(confd,rbuf,sizeof(rbuf),0);
        printf("\nClinet: %s",rbuf);
        if(strcmp(rbuf,"exit")==0){
            break;
        }

        vcCount(rbuf,sbuf);
        printf("\nServer: %s\n",sbuf);
        send(confd,sbuf,sizeof(sbuf),0);
    }
    close(confd);
    close(lfd);
}