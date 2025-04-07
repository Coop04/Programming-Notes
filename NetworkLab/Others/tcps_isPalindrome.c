#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<math.h>

void isPalindrome(char s[],char *result) {
    int count=0,flag=0;
    for(int i=0,j=strlen(s)-1;i<strlen(s),j>=0;i++,j--) {
        if(s[i]==s[j]) {
            count++;
        }
        else {
            flag = 1;
            break;
        }
    }
    if(flag==1) {
        sprintf(result,"%s is not a palindrome",s);
    }
    else {
        sprintf(result,"%s is a palindrome",s);
    }
}

main() {
    struct sockaddr_in server, client;
    int lfd, confd, n;
    char rbuf[100]="", sbuf[100]="";

    lfd = socket(AF_INET,SOCK_STREAM,0);
    
    server.sin_family = AF_INET;
    server.sin_port = 1001;
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
        isPalindrome(rbuf,sbuf);
        printf("\nServer: %s\n",sbuf);
        send(confd,sbuf,sizeof(sbuf),0);
    }
    close(confd);
    close(lfd);
}