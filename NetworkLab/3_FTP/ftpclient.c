/*
 * =====================================================================================
 * | Scenario                  | send()                 | recv()                       |
 * |---------------------------|------------------------|------------------------------|
 * | String (command/message)  | strlen(buf)            | sizeof(buf)-1 + add '\0'     |
 * | Binary data (file/raw)    | byterecv (exact size)  | sizeof(buf) (full buffer)    |
 * =====================================================================================
 */


#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 
#define BUFFER_SIZE 2048 
 
int main(int argc, char *argv[]) { 
    struct sockaddr_in server; 
    int lfd, byterecv; 
    char command[100] = "", filename[100] = "", rBuf[BUFFER_SIZE] = ""; 
    FILE *file; 
 
    lfd = socket(AF_INET, SOCK_STREAM, 0); 
    char *ip_addr = argv[1]; 
    int port = atoi(argv[2]); 
 
    server.sin_family = AF_INET; 
    server.sin_port = htons(port); 
    server.sin_addr.s_addr = inet_addr(ip_addr); 
    connect(lfd, (struct sockaddr *)&server, sizeof(server)); 
 
    printf("\nEnter \"get\" for receiving file from server\nEnter \"close\" for closing connection\n"); 
    while (1) { 
        printf("Enter command: "); 
        scanf("%s", command); 
        if (strcmp(command, "get") == 0) { 
            printf("Enter filename: "); 
            scanf("%s", filename); 
            send(lfd, filename, strlen(filename), 0); 
        
            memset(rBuf, 0, sizeof(rBuf)); 
            // when the file content is empty (ie string is bing returned)
            byterecv = recv(lfd, rBuf, sizeof(rBuf) - 1, 0); //sizeof(rBuf) - 1 + manually add \0 [when recieving string] Ensures space for null-termination.
            rBuf[byterecv] = '\0'; 
        
            if (strncmp(rBuf, "@FILE NOT FOUND", 15) == 0) { 
                    printf("%s \n", rBuf); 
            } else { 
             file = fopen(filename, "w"); 
                if (file) {            
                    fwrite(rBuf, 1, byterecv, file); // This line writes byterecv bytes of data from the buffer rBuf into the file represented by file
                    fprintf(file, "\nFILE %s RECEIVED FROM SERVER WITH PROCESS ID = %d\n", filename, getpid()); 
                    fclose(file); 
                    printf("%s is received\n", filename); 
                } else { 
                    printf("Error creating the file on client.\n"); 
                } 
            } 
        } else if (strcmp(command, "close") == 0) { 
            send(lfd, command, strlen(command), 0); 
            break; 
        } else { 
            printf("Invalid command\n"); 
        } 
    } 
    close(lfd); 
    return 0; 
}