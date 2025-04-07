#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>
FILE *f1;

struct array{
    int a[50];
} data;

main()
{
    struct sockaddr_in server;
    int lfd,limit;
    char choice[10]="";
    f1 = fopen("output.txt", "w");

    lfd=socket(AF_INET,SOCK_STREAM,0);

    server.sin_family=AF_INET;
    server.sin_port=5221;
    server.sin_addr.s_addr=inet_addr("127.0.0.1");

    printf("\nClient ready....\n");
    connect(lfd,(struct sockaddr *)&server,sizeof server);
	while(1)
	{   printf("\nEnter the limit: ");
        scanf("%d",&limit);

		send(lfd,&limit,sizeof limit,0);
		recv(lfd,&data,sizeof data,0);

		printf("The prime numbers are \n");
		fprintf(f1,"The prime numbers are \n");
        fflush(f1);
		for(int i=0;data.a[i]!=-1;i++) {
			printf("%d\t",data.a[i]);
			fprintf(f1,"%d\t",data.a[i]);
            fflush(f1);
        }
        fprintf(f1,"\n");
        fflush(f1);
		printf("\nDo you like to continue (y/n) :");
		scanf("%s",choice);
		send(lfd,choice,sizeof choice,0);
		if(strcmp(choice,"n")==0)
		{
			break;
		}
	  	printf("\n");
   }   
    fclose(f1);
    close(lfd);
}
