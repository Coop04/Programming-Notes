/*
 * =====================================================================================
 * | Scenario                  | send()                 | recv()                       |
 * |---------------------------|------------------------|------------------------------|
 * | String (command/message)  | strlen(buf)            | sizeof(buf)-1 + add '\0'     |
 * | Binary data (file/raw)    | byterecv (exact size)  | sizeof(buf) (full buffer)    |
 * =====================================================================================
 */


#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/stat.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define MAX 2048

main() {
    struct sockaddr_in server,client;
    int lfd,confd,n,byterecv;
    char buf[MAX]="";

    lfd = socket(AF_INET,SOCK_STREAM,0);

    server.sin_family = AF_INET;
    server.sin_port = 2001;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind(lfd,(struct sockaddr*)&server,sizeof(server));
    listen(lfd,1);

    printf("\nSrever is ready..\n");

    n = sizeof(client);
    confd = accept(lfd,(struct sockaddr*)&client,&n);

    while(1) {
        strcpy(buf,"");
        byterecv = recv(confd,buf,sizeof(buf)-1,0); // receiving filename (string)

        if(byterecv <= 0)
            break;
        if(strcmp(buf,"exit")==0)
            break;
        buf[byterecv] = '\0';

        FILE *f1 = fopen(buf,"r");

        if(f1 == NULL) {
            sprintf(buf,"@FILE NOT FOUND, PROCESS ID = %d\n",getpid());
            send(confd,buf,strlen(buf),0);
        }
        else {
            while((byterecv = fread(buf,1,sizeof(buf),f1))>0) { //sizeof(buf)means sizeof(filename) meaning size of the file
                send(confd,buf,byterecv,0);
            }
            fclose(f1);
        }
    }
    close(confd);
    close(lfd);
}