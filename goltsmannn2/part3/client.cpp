#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>

#define PORT 8000
int main(){
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(PORT);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
    const char* message = "Hello, server!";
    send(clientSocket, message, strlen(message), 0);
    close(clientSocket);
}

