#include <iostream>
#include <cstring>
#include "info.pb.h"
#include "mainFile.hpp"

mainServer::mainServer (const std::string server_ip, int server_port) {
    newSocket = socket(AF_INET, SOCK_DGRAM, 0);

    if (newSocket < 0) {
        std::cout << "Socket cannot be created" << std::endl;
        exit(1);
    }

    memset((char *)&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, server_ip.c_str(), &server_addr.sin_addr);
    server_addr.sin_port = htons(server_port);

    if (bind(newSocket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        std::cout << "Socket cannot be binded to" << std::endl;
        exit(1);
    }
};

bool mainServer::send(info::data message, int backToServer) {

    std::string serialized;

    if (!message.SerializeToString(&serialized)) {
        std::cout << "Message could not be serialized" << std::endl;
        return false;
    }


    if (backToServer == 0) {
        if (sendto(newSocket, serialized.data(), serialized.size(), 0, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            std::cout << "Message could not be sent" << std::endl;
            return false;
        }
    } else {
        if (sendto(newSocket, serialized.data(), serialized.size(), 0, (struct sockaddr *)&rem_addr, sizeof(rem_addr)) < 0) {
            std::cout << "Message could not be sent" << std::endl;
            return false;
        }
    }

    return true;
}

bool mainServer::receive(info::data message)
{
    char buffer[1024];

    socklen_t addr_len = sizeof(rem_addr);

    int received = recvfrom(newSocket, buffer, 1024, 0, (struct sockaddr*)&rem_addr, &addr_len);

    if (received < 0) {
        std::cout << "Data was not received" << std::endl;
        return false;
    }

    if (!message.ParseFromArray(buffer, received)) {
        std::cout << "Data could not be parsed" << std::endl;
        return false;
    }

    std::cout << "Data received" << std::endl;

    return true;
}

void mainServer::close() {
    ::close(newSocket);
}

