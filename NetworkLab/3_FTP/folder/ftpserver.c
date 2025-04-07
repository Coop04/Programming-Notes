/*
 * =====================================================================================
 * | Scenario                  | send()                 | recv()                       |
 * |---------------------------|------------------------|------------------------------|
 * | String (command/message)  | strlen(buf)            | sizeof(buf)-1 + add '\0'     |
 * | Binary data (file/raw)    | byterecv (exact size)  | sizeof(buf) (full buffer)    |
 * =====================================================================================
 */

#include <stdio.h> 
#include <string.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 
#define BUFFER_SIZE 2048 
int main() { 
    struct sockaddr_in client, server; 
    int lfd, n, confd, byterecv; 
    char rBuf[BUFFER_SIZE] = ""; 
    lfd = socket(AF_INET, SOCK_STREAM, 0); 
 
    server.sin_family = AF_INET; 
    server.sin_port = htons(5555); 
    server.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    bind(lfd, (struct sockaddr *)&server, sizeof server); 
    listen(lfd, 1); 
    n = sizeof client; 
    confd = accept(lfd, (struct sockaddr *)&client, &n); 
 
    while (1) { 
        strcpy(rBuf, ""); 
        byterecv = recv(confd, rBuf, sizeof(rBuf)-1, 0); 
        if (byterecv <= 0) 
            break; 
        if (strcmp(rBuf, "close") == 0) 
            break; 
        rBuf[byterecv] = '\0'; 
 
        FILE *file = fopen(rBuf, "r"); 
        if (file == NULL) { 
            sprintf(rBuf, "@FILE NOT FOUND PROCESS ID = %d\n", getpid()); 
            send(confd, rBuf, strlen(rBuf), 0); // strlen() [used when sending strings] We only want to send the actual string length (excluding \0).
        } else { 
            while ((byterecv = fread(rBuf, 1, sizeof(rBuf), file)) > 0) { // [fread converts the file contents to string and store it in rbuf and store the no. of bytes in byterecv] fread attempts to read up to BUFFER_SIZE bytes from the file into rBuf.
                send(confd, rBuf, byterecv, 0); 
            } 
            fclose(file); 
        } 
    } 
    close(lfd); 
    close(confd); 
    return 0; 
} 