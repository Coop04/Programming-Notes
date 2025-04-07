#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<math.h> // gcc tcps_amstrong.c -o tcps_amstrong -lm (to link math.h to compiler)

void armstrong(int a,char *result) {
    int count=0,num = a,sum = 0,r;
    while(a!=0) {
        a = a/10;
        count++;
    }
    a = num;
    while(a!=0) {
        r = a%10;
        sum += pow(r,count);
        a = a/10;
    }
    if(sum==num) {
        sprintf(result,"%d is an amstrong number",num);
    }
    else {
        sprintf(result,"%d is not an amstrong number",num);
    }
}

main() {
    struct sockaddr_in server, client;
    int lfd, confd, n;
    char rbuf[100]="", sbuf[100]="";

    lfd = socket(AF_INET,SOCK_STREAM,0);
    
    server.sin_family = AF_INET;
    server.sin_port = 5555;
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
        int num = atoi(rbuf);
        armstrong(num,sbuf);
        printf("\nServer: %s\n",sbuf);
        send(confd,sbuf,sizeof(sbuf),0);
    }
    close(confd);
    close(lfd);
}