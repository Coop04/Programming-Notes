#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>

void numPal(int num, char *result) {
    int rem,rev=0,n=num;
    while(num!=0) {
        rem = num%10;
        rev = rev*10 +rem;
        num = num/10;
    }
    if(n==rev)
        sprintf(result,"%d is palindrome",rev);
    else
        sprintf(result,"%d is not palindrome",rev);
}

main() {
    struct sockaddr_in server,client;
    int lfd,n,num;
    char sbuf[100]="",rbuf[100]="";

    lfd=socket(AF_INET,SOCK_DGRAM,0);

    server.sin_family=AF_INET;
    server.sin_port=2000;
    server.sin_addr.s_addr=inet_addr("127.0.0.1");

    bind(lfd,(struct sockaddr*)&server,sizeof(server));

    printf("Server ready...\n");

    n=sizeof(client);

    while(1) {
        recvfrom(lfd,rbuf,sizeof(rbuf),0,(struct sockaddr*)&client,&n);
        if(strcmp(rbuf,"exit")==0) {
            break;
        }
        printf("Client: %s\n",rbuf);
        num = atoi(rbuf);
        numPal(num,sbuf);
        printf("Server: %s\n",sbuf);
        sendto(lfd,sbuf,sizeof(sbuf),0,(struct sockaddr*)&client,n);
    }
    close(lfd);
}