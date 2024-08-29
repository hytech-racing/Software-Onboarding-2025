// Client.cpp
#include "client_driver.h"
#include <google/protobuf/message.h>
#include <iostream>
#include <cstring> // For memset

// FIX
#include "christine.pb.h"
#include "hytech.pb.h"

/**
 * @brief Class Client
 * 
 * Set up socket
 */
Client::Client(const std::string& server_ip, uint16_t server_port) {
    // Create socket
    _sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (_sockfd < 0) {
        std::cerr << "Failed to create socket" << std::endl;
        exit(1);
    }

    // Setup server address
    memset(&_server_addr, 0, sizeof(_server_addr));
    _server_addr.sin_family = AF_INET;
    _server_addr.sin_port = htons(server_port);
    inet_pton(AF_INET, server_ip.c_str(), &_server_addr.sin_addr);
}

Client::~Client() {
    close(_sockfd);
}
/**
 * @brief Class Client
 * 
 * sends message to the server
 */
bool Client::SendMessage(const christine::Client& message) {
    std::string serialized_message;
    if (!message.SerializeToString(&serialized_message)) {
        std::cerr << "Failed to serialize message" << std::endl;
        return false;
    }

    if (sendto(_sockfd, serialized_message.data(), serialized_message.size(), 0, 
               (struct sockaddr*)&_server_addr, sizeof(_server_addr)) < 0) {
        std::cerr << "Failed to send message" << std::endl;
        return false;
    }
    return true;
}
/**
 * @brief Class Client
 * 
 * sends response to the server
 */
bool Client::ReceiveMessage(hytech::Server& message) {
    char buffer[_BUFFER_SIZE];
    sockaddr_in from_addr;
    socklen_t from_addr_len = sizeof(from_addr);

    ssize_t received_bytes = recvfrom(_sockfd, buffer, _BUFFER_SIZE, 0, 
                                      (struct sockaddr*)&from_addr, &from_addr_len);
    if (received_bytes < 0) {
        std::cerr << "Failed to receive message" << std::endl;
        return false;
    }

    if (!message.ParseFromArray(buffer, received_bytes)) {
        std::cerr << "Failed to parse message" << std::endl;
        return false;
    }

    std::cout << "Received message from " << message.sender_name()  << ": " << message.message() << std::endl;
    return true;
}
