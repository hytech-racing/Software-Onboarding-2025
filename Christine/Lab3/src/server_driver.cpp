#include "server_driver.h"
#include <google/protobuf/message.h>
#include <iostream>
#include <cstring> // For memset


#include "christine.pb.h"
#include "hytech.pb.h"

/**
 * @brief Class Server
 * 
 * Set up socket
 */
Server::Server(const std::string& server_ip, uint16_t server_port) {
    _sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (_sock < 0) {
        std::cerr << "Failed to create socket" << std::endl;
        exit(1);
    }

    // Setup server address
    memset(&_server_addr, 0, sizeof(_server_addr));
    _server_addr.sin_family = AF_INET;
    _server_addr.sin_port = htons(server_port);
    inet_pton(AF_INET, server_ip.c_str(), &_server_addr.sin_addr);

    if (bind(_sock, (struct sockaddr*)&_server_addr, sizeof(_server_addr)) < 0) {
        std::cerr << "Failed to bind socket" << std::endl;
        exit(1);
    }
}

Server::~Server() {
    close(_sock);
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

    if (sendto(_sock, serialized_message.data(), serialized_message.size(), 0,
                (struct sockaddr*)&_client_addr, sizeof(_client_addr)) < 0) {
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
    char buffer[_BUFFER_SIZE];
    socklen_t _client_addr_len = sizeof(_client_addr);

    ssize_t received_bytes = recvfrom(_sock, buffer, _BUFFER_SIZE, 0, 
                                      (struct sockaddr*)&_client_addr, &_client_addr_len);
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