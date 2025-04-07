#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define MAX 2049

main(int argc,char *argv[]) {
    struct sockaddr_in server,client;
    int lfd,byterecv;
    char filename[100]="",command[100]="",buf[MAX]="";
    FILE *f;

    lfd = socket(AF_INET,SOCK_STREAM,0);
    char *ip_addr = argv[1];
    int port = atoi(argv[2]);

    server.sin_family = AF_INET;
    server.sin_port = port;
    server.sin_addr.s_addr = inet_addr(ip_addr);

    connect(lfd,(struct sockaddr *)&server,sizeof(server));

    printf("Client is ready...\n");

    printf("Enter get or close\n");
    while(1) {
        printf("Enter the command: ");
        scanf("%s",command);
        if(strcmp(command,"get")==0) {
            printf("Enter filename: ");
            scanf("%s",filename);
            send(lfd,filename,strlen(filename),0);
            byterecv = recv(lfd,buf,sizeof(buf)-1,0);
            buf[byterecv]='\0';

            if(strncmp(buf,"@FILE NOT FOUND",15)==0) {
                printf("%s\n",buf);
            }
            else {
                f = fopen(filename,"w");
                if(f) {
                    fwrite(buf,1,strlen(buf),f);
                    fclose(f);
                    printf("File recieved\n");
                }
                else {
                    printf("Error!!!!!\n");
                }
            }
        }
        else if(strcmp(command,"close")==0) {
            send(lfd,command,strlen(command),0);
            break;
        }
        else {
            printf("Invalid command\n");
        }
    }
}