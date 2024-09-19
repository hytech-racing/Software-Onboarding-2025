#include <iostream>
#include <cstring>
#include "info.pb.h"
#include "mainFile.hpp"

int newSocket;

mainServer::mainServer (const std::string server_ip, int server_port) {
    newSocket = socket(AF_INET, SOCK_DGRAM, 0);

    if (newSocket < 0) {
        std::cout << "Socket cannot be created" << std::endl;
        exit(1);
    }
    
    struct sockaddr_in server_addr;

    memset((char *)&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(server_port);
    inet_pton(AF_INET, server_ip.c_str(), &server_addr.sin_addr);

    if (bind(newSocket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        std::cout << "Socket cannot be binded to" << std::endl;
        exit(1);
    }
};

bool mainServer::send(info::data message, int port) {

    std::string serialized;

    if (!message.SerializeToString(&serialized)) {
        std::cout << "Message could not be serialized" << std::endl;
        return false;
    }

    struct sockaddr_in client_addr;

    memset((char *)&client_addr, 0, sizeof(client_addr));
    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(port);

    if (sendto(newSocket, serialized.data(), serialized.size(), 0, (struct sockaddr *)&client_addr, sizeof(client_addr)) < 0) {
        std::cout << "Message could not be sent" << std::endl;
        return false;
    }

    return true;
}

bool mainServer::receive(info::data message)
{
    char buffer[1024];

    struct sockaddr_in clientAddr;

    socklen_t addr_len = sizeof(clientAddr);

    int received = recvfrom(newSocket, buffer, 1024, 0, (struct sockaddr*)&clientAddr, &addr_len);

    if (received < 0) {
        std::cout << "Data was not received" << std::endl;
        return false;
    }

    if (!message.ParseFromArray(buffer, received)) {
        std::cout << "Data could not be parsed" << std::endl;
        return false;
    }
    return true;
}

void mainServer::close() {
    ::close(newSocket);
}

