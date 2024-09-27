#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <protobuf.pb.h>

#define PORT 8000


int main(){
    const int clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(PORT);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
    OnboardingLab3::SimpleMessage message;
    std::string name, msg;
    std::cin >> name >> msg;
    message.set_sender_name(name);
    message.set_sender_message(msg);
    std::string test;
    message.SerializeToString(&test);
    send(clientSocket, test.c_str(), test.size(), 0);
    close(clientSocket);

    return 0;
}

