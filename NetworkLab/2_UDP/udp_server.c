// UDP Server (Palindrome Check)
#include<stdio.h> 
#include<string.h> 
#include<sys/stat.h> 
#include<sys/types.h> 
#include<sys/socket.h> 
#include<netinet/in.h> 
#include<arpa/inet.h> 
#include<stdlib.h> 

main() 
{ 
    struct sockaddr_in client, server; // Structures to store client and server address information
    int lfd, n; // lfd = listening socket, n = size of client structure
    char rBuf[100] = "", sBuf[100] = "";  // Buffers for receiving and sending messages  

    lfd = socket(AF_INET, SOCK_DGRAM, 0); // Create a UDP socket (SOCK_DGRAM means UDP)

    server.sin_family = AF_INET;  // Use IPv4  
    server.sin_port = 2001;       // Set port number to 2001  
    server.sin_addr.s_addr = inet_addr("127.0.0.1"); // Assign localhost IP address  

    bind(lfd, (struct sockaddr *)&server, sizeof(server)); // Bind the socket to the IP and port  
    printf("\nServer ready, waiting for client....\n");  

    n = sizeof(client); 

    // Receive message (number) from client
    recvfrom(lfd, rBuf, sizeof(rBuf), 0, (struct sockaddr *)&client, &n); 
    printf("\nClient: %s", rBuf); 

    int num = atoi(rBuf); // Convert received string to integer
    int rev = 0, rem, copy = num; // Variables for palindrome check

    // Reverse the number
    while (num != 0) 
    { 
        rem = num % 10; 
        rev = rev * 10 + rem; 
        num = num / 10; 
    } 

    // Check if the original number is the same as the reversed number
    if (copy == rev) 
        strcpy(sBuf, "palindrome"); 
    else 
        strcpy(sBuf, "not palindrome"); 

    printf("\nServer: %s", sBuf);  

    // Send result back to the client
    sendto(lfd, sBuf, sizeof(sBuf), 0, (struct sockaddr *)&client, n); 

    close(lfd); // Close the socket  
} 
