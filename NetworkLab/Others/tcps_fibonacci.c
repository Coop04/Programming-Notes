#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<math.h>
struct array{
    int a[50];
} data;
void fibo(int l,struct array *data) {
    int a=0,b=1,c,i;
    data->a[0] = a;
    data->a[1] = b;
    for(i=2;i<l;i++) {
        c=a+b;
        data->a[i]=c;
        a=b;
        b=c;
    }
    data->a[i]=-1;
}

main() {
    struct sockaddr_in server, client;
    int lfd, confd, n, limit;
    char choice[10];

    lfd = socket(AF_INET,SOCK_STREAM,0);
    
    server.sin_family = AF_INET;
    server.sin_port = 5221;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind(lfd,(struct sockaddr*)&server, sizeof(server));
    listen(lfd,1);

    printf("\nServer is ready....\n");
    n = sizeof(client);
    confd = accept(lfd,(struct sockaddr *)&client, &n);

    while(1) {
        recv(confd,&limit,sizeof(limit),0);
        fibo(limit,&data);
        send(confd,&data,sizeof(data),0);
        recv(confd,choice,sizeof(choice),0);
        if(strcmp(choice,"n")==0){
            break;
        }
    }
    close(confd);
    close(lfd);
}