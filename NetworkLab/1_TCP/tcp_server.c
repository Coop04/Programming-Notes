// TCP Chat : Server (chat program) 
// Type "exit" from client side to terminate   

#include<stdio.h>     // Standard I/O functions
#include<string.h>    // String handling functions (e.g., strcmp)
#include<sys/stat.h>  
#include<sys/types.h> 
#include<sys/socket.h> // Socket programming functions
#include<netinet/in.h> // Internet address structures
#include<arpa/inet.h>  // Functions for working with IP addresses
#include<stdlib.h>     // Standard library functions (e.g., exit)

main()  
{   
    struct sockaddr_in client, server; // Structures to store client and server address information   
    int lfd, n, confd;    // lfd = listening socket, confd = connection socket, n = size of client structure
    char rBuf[100] = "", sBuf[100] = "";  // Buffers to store received and sent messages   

    lfd = socket(AF_INET, SOCK_STREAM, 0);  // Create a TCP socket (SOCK_STREAM means TCP)

    server.sin_family = AF_INET;   // Use IPv4  
    server.sin_port = 2000;        // Port number 2000 for communication  
    server.sin_addr.s_addr = inet_addr("127.0.0.1"); // Assign localhost IP address  

    bind(lfd, (struct sockaddr *)&server, sizeof(server)); // Bind the socket to the IP and port  
    listen(lfd, 1);  // Start listening for client connections (max 1 client in queue)  

    printf("\nServer ready, waiting for client....\n");  // Inform that the server is ready  

    n = sizeof(client);     
    confd = accept(lfd, (struct sockaddr *)&client, &n); // Accept a client connection  

    while (1)  // Infinite loop to keep the chat running  
    { 
        recv(confd, rBuf, sizeof(rBuf), 0);  // Receive message from the client  
        printf("\nClient: %s", rBuf); // Print the received message  

        if (strcmp(rBuf, "exit") == 0) // Check if the client wants to exit  
            break; // If "exit" is received, break the loop and close the connection  

        printf("\nServer:  ");      
        gets(sBuf); // Get message input from the server  
            
        send(confd, sBuf, sizeof(sBuf), 0); // Send the server's message to the client  
        
        if (strcmp(sBuf, "exit")==0)
            break;
            
        printf("\n");     
    } 
    
    close(confd); // Close the connection socket  
    close(lfd);   // Close the listening socket  
}
