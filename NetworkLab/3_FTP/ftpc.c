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
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define MAX 2048

main(int argc,char *argv[]) {
    struct sockaddr_in server;
    int lfd,byterecv;
    char filename[100]="",command[100]="",buf[MAX]="";
    FILE *f1;

    lfd = socket(AF_INET,SOCK_STREAM,0);
    char *ip_addr = argv[1];
    int port = atoi(argv[2]);

    server.sin_family = AF_INET;
    server.sin_port = port;
    server.sin_addr.s_addr = inet_addr(ip_addr);

    connect(lfd,(struct sockaddr*)&server,sizeof(server));

    
    printf("Enter get or exit\n");
    while(1) {
        printf("Enter a command: ");
        scanf("%s",command);
        if(strcmp(command,"get")==0) {
            printf("\nEnter filename: ");
            scanf("%s",filename);
            send(lfd,filename,strlen(filename),0);

            strcpy(buf,"");
            byterecv = recv(lfd,buf,sizeof(buf)-1,0);
            buf[byterecv]='\0';

            if(strncmp(buf,"@FILE NOT FOUND",15)==0) {
                printf("%s",buf);
            }
            else {
                f1 = fopen(filename,"w");
                if(f1) {
                    fwrite(buf,1,byterecv,f1);
                    fclose(f1);
                    printf("\nFile recieved!!\n");
                }
                else {
                    printf("Error!");
                }
            }
        }
        else if(strcmp(command,"exit")==0) {
            send(lfd,command,strlen(command),0);
            break;
        }
        else {
            printf("\nInvalid Command!\n");
        }
        }
    close(lfd);
}