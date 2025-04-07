// TCP Multi Chat : Client

#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>

struct array{
	int size;
	int a[50];
}data;

int main()
{
    struct sockaddr_in server;
    int lfd;
    char choice[10];

    lfd=socket(AF_INET,SOCK_STREAM,0);

    server.sin_family=AF_INET;
    server.sin_port=htons(2011);
    server.sin_addr.s_addr=inet_addr("127.0.0.1");

    printf("\nClient ready....\n");
    connect(lfd,(struct sockaddr *)&server,sizeof server);
	while(1)
	{	
		printf("\nEnter Size of array :" );
		scanf("%d",&data.size);
		printf("\nEnter the array :" );
		for(int i=0;i<data.size;i++)
			scanf("%d",&data.a[i]);

		send(lfd,&data,sizeof data,0);
		recv(lfd,&data,sizeof data,0);

		printf("The Sorted array \n");
		for(int i=0;i<data.size;i++)
			printf("%d,",data.a[i]);
		
		printf("\nDo you like to continue (y/n) :");
		scanf("%s",choice);
		send(lfd,choice,sizeof choice,0);
		if(strcmp(choice,"n")==0)
		{
			break;
		}
	  	printf("\n");
   }   
    close(lfd);
   return 0;
}
