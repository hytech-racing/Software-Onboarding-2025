// Client.cpp
#include "../include/client_driver.h"
#include <google/protobuf/message.h>
#include <iostream>
#include <cstring> // For memset
#include "../proto/christine/christine.pb.h"
#include "../proto/hytech/hytech.pb.h"

/**
 * @brief Class Client
 * 
 * Set up socket
 */
Client::Client(const std::string& server_ip, uint16_t server_port) {
    // Create socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        std::cerr << "Failed to create socket" << std::endl;
        exit(1);
    }

    // Setup server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    inet_pton(AF_INET, server_ip.c_str(), &server_addr.sin_addr);
}

Client::~Client() {
    close(sockfd);
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

    if (sendto(sockfd, serialized_message.data(), serialized_message.size(), 0, 
               (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
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
    char buffer[BUFFER_SIZE];
    sockaddr_in from_addr;
    socklen_t from_addr_len = sizeof(from_addr);

    ssize_t received_bytes = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, 
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
