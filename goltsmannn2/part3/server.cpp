#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <protobuf.pb.h>

#define PORT 8000

int main()
{
    // creating socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    // specifying the address
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(PORT);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    // binding socket.
    bind(serverSocket, (struct sockaddr*)&serverAddress,
         sizeof(serverAddress));

    // listening to the assigned socket
    listen(serverSocket, 5);

    // accepting connection request
    int clientSocket
        = accept(serverSocket, nullptr, nullptr);

    // recieving data
    char buffer[1024] = { 0 };
    auto len = recv(clientSocket, buffer, sizeof(buffer), 0);
    std::cout << len << std::endl;
    OnboardingLab3::SimpleMessage receivedMessage;
    std::cout << receivedMessage.ParseFromString(std::string(buffer)) << std::endl;
    std::cout << "Name of client: " << receivedMessage.sender_name() << ", message from client: " << receivedMessage.sender_message();

    // closing the socket.
    close(serverSocket);

    return 0;
}