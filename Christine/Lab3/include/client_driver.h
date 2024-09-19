#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <arpa/inet.h>  // For sockaddr_in
#include <sys/socket.h> // For socket functions
#include <unistd.h>     // For close

// FIX
#include "christine.pb.h"
#include "hytech.pb.h"

/**
 * @brief Class Client
 * 
 * Header file for the client driver
 */
class Client {
public:
    Client(const std::string& server_ip, uint16_t server_port);
    ~Client();

    bool SendMessage(const christine::Client& message);
    bool ReceiveMessage(hytech::Server& message);

private:
    int _sockfd;
    sockaddr_in _server_addr;
    static const int _BUFFER_SIZE = 1024;
};

#endif // CLIENT_H
