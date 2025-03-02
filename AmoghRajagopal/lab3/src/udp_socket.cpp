#include "udp_socket.h"
#include <iostream>
#include <cstring>      
#include <arpa/inet.h>  
#include <unistd.h>     

UdpSocket::UdpSocket(int port) {
    //Create our UDP socket
    socketFd = socket(AF_INET, SOCK_DGRAM, 0);
    if (socketFd < 0) {
        std::cerr << "Error creating socket" << std::endl;
        exit(EXIT_FAILURE);
    }

    //Configure socket address structure 
    sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (port != 0) {
        if (bind(socketFd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
            std::cerr << "Error binding socket to port " << port << std::endl;
            close(socketFd);
            exit(EXIT_FAILURE);
        }
    }
    
    this->port = port;
}

UdpSocket::~UdpSocket() {
    close(socketFd);  
}

void UdpSocket::sendMessage(const std::string& message, const std::string& ipAddress, int port) {
    sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, ipAddress.c_str(), &server_addr.sin_addr);

    ssize_t sent_bytes = sendto(socketFd, message.c_str(), message.size(), 0,
                                (struct sockaddr*)&server_addr, sizeof(server_addr));

    if (sent_bytes < 0) {
        std::cerr << "Error sending message" << std::endl;
    }
}

void UdpSocket::receiveMessage(std::string& message, std::string& senderIp, int& port) {
    char buffer[1024];
    sockaddr_in sender_addr;
    socklen_t sender_len = sizeof(sender_addr);

    ssize_t received_bytes = recvfrom(socketFd, buffer, sizeof(buffer) - 1, 0,
                                      (struct sockaddr*)&sender_addr, &sender_len);
    if (received_bytes < 0) {
        std::cerr << "Error receiving message" << std::endl;
        return;
    }

    buffer[received_bytes] = '\0'; 
    message = std::string(buffer, received_bytes);

    char senderIp_buffer[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &sender_addr.sin_addr, senderIp_buffer, sizeof(senderIp_buffer));
    senderIp = std::string(senderIp_buffer);
    port = ntohs(sender_addr.sin_port);
}
