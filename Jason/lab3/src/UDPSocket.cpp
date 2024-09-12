#include "UDPSocket.hpp"
#include <unistd.h>
#include <cstring>
#include <iostream>

UDPSocket::UDPSocket() {
    // Create the socket using IPv4 and UDP
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        std::cerr << "Error creating socket\n";
    }

    // Initialize local and remote address structs
    memset(&localAddr, 0, sizeof(localAddr));
    memset(&remoteAddr, 0, sizeof(remoteAddr));
}

UDPSocket::~UDPSocket() {
    closeSocket();
}

bool UDPSocket::bindSocket(const std::string& ip, int port) {
    localAddr.sin_family = AF_INET;
    localAddr.sin_port = htons(port);
    localAddr.sin_addr.s_addr = inet_addr(ip.c_str());

    // Bind the socket to the specified IP and port
    if (bind(sockfd, (struct sockaddr*)&localAddr, sizeof(localAddr)) < 0) {
        std::cerr << "Error binding socket to " << ip << ":" << port << "\n";
        return false;
    }

    return true;
}

ssize_t UDPSocket::sendTo(const std::string& message, const std::string& ip, int port) {
    remoteAddr.sin_family = AF_INET;
    remoteAddr.sin_port = htons(port);
    remoteAddr.sin_addr.s_addr = inet_addr(ip.c_str());

    ssize_t bytesSent = sendto(sockfd, message.c_str(), message.length(), 0, 
                               (struct sockaddr*)&remoteAddr, sizeof(remoteAddr));
    if (bytesSent < 0) {
        std::cerr << "Error sending message\n";
    }
    return bytesSent;
}

ssize_t UDPSocket::receiveFrom(std::string& message, std::string& senderIp, int& senderPort) {
    char buffer[1024];
    socklen_t addrLen = sizeof(remoteAddr);
    ssize_t bytesReceived = recvfrom(sockfd, buffer, sizeof(buffer), 0, 
                                     (struct sockaddr*)&remoteAddr, &addrLen);

    if (bytesReceived > 0) {
        message = std::string(buffer, bytesReceived);
        senderIp = inet_ntoa(remoteAddr.sin_addr);
        senderPort = ntohs(remoteAddr.sin_port);
    } else {
        std::cerr << "Error receiving message\n";
    }

    return bytesReceived;
}

void UDPSocket::closeSocket() {
    if (sockfd >= 0) {
        close(sockfd);
    }
}
