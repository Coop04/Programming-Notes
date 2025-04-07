// TCP Multi Chat : Server

#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>
#include<ctype.h>

struct array{
	int size;
	int a[50];
}data;
void bubblesort(struct array *data) {
    int temp;
    for (int i = 0; i < data->size - 1; i++) {
        for (int j = 0; j < data->size - i - 1; j++) { 
            if (data->a[j] > data->a[j + 1]) {
                temp = data->a[j];
                data->a[j] = data->a[j + 1];
                data->a[j + 1] = temp;
            }
        }
    }
}


int main()
{
    struct sockaddr_in client,server;
    int lfd,n,confd;
    char choice;
    pid_t childpid;	//
    
    lfd=socket(AF_INET,SOCK_STREAM,0); 
    
    server.sin_family=AF_INET;
    server.sin_port=htons(2011);
    server.sin_addr.s_addr=inet_addr("127.0.0.1");

    bind(lfd,(struct sockaddr *)&server,sizeof server);	
    listen(lfd,5); //queue  of pending  connections is 5

	while(1)
	{
		 printf("\nServer ready,waiting for client....\n");    
		 n=sizeof client;
		 confd=accept(lfd,(struct sockaddr *)&client,&n);
		 if ((childpid = fork()) == 0) 
		{
			close(lfd);
			while(1)
			{
				recv(confd,&data,sizeof data,0);
				bubblesort(&data);
			
				send(confd,&data,sizeof data,0);
				recv(confd,choice,sizeof choice,0);
				if(strcmp(choice,"n")==0) // it is the choice, whether to break or continue
				   break;
		 	}		         
		}
		 close(confd);
    }
    //exit (0);
}

