#include "../include/server_driver.h"
#include <google/protobuf/message.h>
#include <iostream>
#include <cstring> // For memset
#include "../proto/christine/christine.pb.h"
#include "../proto/hytech/hytech.pb.h"

/**
 * @brief Class Server
 * 
 * Set up socket
 */
Server::Server(const std::string& server_ip, uint16_t server_port) {
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        std::cerr << "Failed to create socket" << std::endl;
        exit(1);
    }

    // Setup server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    inet_pton(AF_INET, server_ip.c_str(), &server_addr.sin_addr);

    if (bind(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Failed to bind socket" << std::endl;
        exit(1);
    }
}

Server::~Server() {
    close(sock);
}

/**
 * @brief Class Server
 * 
 * Sends response message to client
 */
bool Server::SendMessage(const hytech::Server& message) {

    std::string serialized_message;
    if (!message.SerializeToString(&serialized_message)) {
        std::cerr << "Failed to serialize message" << std::endl;
        return false;
    }

    if (se  ndto(sock, serialized_message.data(), serialized_message.size(), 0,
                (struct sockaddr*)&client_addr, sizeof(client_addr)) < 0) {
        std::cerr << "Failed to send message" << std:: endl;
    }
    return true;
}

/**
 * @brief Class Server
 * 
 * Receives message from client
 */
bool Server::ReceiveMessage(christine::Client& message) {
    char buffer[BUFFER_SIZE];
    socklen_t client_addr_len = sizeof(client_addr);

    ssize_t received_bytes = recvfrom(sock, buffer, BUFFER_SIZE, 0, 
                                      (struct sockaddr*)&client_addr, &client_addr_len);
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