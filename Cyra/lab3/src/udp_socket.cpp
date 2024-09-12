#include "udp_socket.h"
#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

UdpSocket::UdpSocket(int port) : port(port) {
    socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (socket_fd < 0) {
        std::cerr << "Failed to create socket\n";
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Failed to bind socket\n";
        exit(EXIT_FAILURE);
    }
}

UdpSocket::~UdpSocket() {
    close(socket_fd);
}

void UdpSocket::sendMessage(const std::string& message, const std::string& ipAddress, int port) {
    struct sockaddr_in client_addr;
    memset(&client_addr, 0, sizeof(client_addr));
    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(port);
    inet_pton(AF_INET, ipAddress.c_str(), &client_addr.sin_addr);

    sendto(socket_fd, message.c_str(), message.size(), 0, (struct sockaddr*)&client_addr, sizeof(client_addr));
}

void UdpSocket::receiveMessage(std::string& message, std::string& sender_ip, int& port) {
    char buffer[1024];
    struct sockaddr_in client_addr;
    socklen_t addr_len = sizeof(client_addr);

    // Receive message
    int bytes_received = recvfrom(socket_fd, buffer, sizeof(buffer) - 1, 0, (struct sockaddr*)&client_addr, &addr_len);
    if (bytes_received > 0) {
        buffer[bytes_received] = '\0';
        message = std::string(buffer);
        
        // Extract sender's IP and port
        char client_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(client_addr.sin_addr), client_ip, INET_ADDRSTRLEN);
        sender_ip = std::string(client_ip);
        port = ntohs(client_addr.sin_port);
    } else {
        message = "";
    }
}


