// UDP Client (Palindrome Check)
#include<stdio.h> 
#include<string.h> 
#include<sys/stat.h> 
#include<sys/types.h> 
#include<sys/socket.h> 
#include<netinet/in.h> 
#include<arpa/inet.h>  

main() 
{     
    struct sockaddr_in server;  // Structure to store server address
    int lfd, n; // lfd = socket file descriptor, n = size of server structure
    char rBuf[100] = "", sBuf[100] = ""; // Buffers for sending and receiving messages      

    lfd = socket(AF_INET, SOCK_DGRAM, 0); // Create a UDP socket (SOCK_DGRAM means UDP)    

    server.sin_family = AF_INET;  // Use IPv4    
    server.sin_port = 2001;       // Set port number to 2001      
    server.sin_addr.s_addr = inet_addr("127.0.0.1"); // Assign localhost IP address    

    printf("\nClient ready....\n");   
    n = sizeof(server);     

    printf("\nClient: ");     
    gets(sBuf); // Get user input (a number)     

    // Send the user input to the server
    sendto(lfd, sBuf, sizeof(sBuf), 0, (struct sockaddr *)&server, n);     

    // Receive the response from the server
    recvfrom(lfd, rBuf, sizeof(rBuf), 0, (struct sockaddr *)&server, &n);     

    printf("\nServer: %s", rBuf);  // Print the server's response    

    close(lfd); // Close the socket  
} 
