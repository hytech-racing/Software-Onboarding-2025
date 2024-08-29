#ifndef SERVER_H
#define SERVER_H

#include <string>
#include <arpa/inet.h>  // For sockaddr_in
#include <sys/socket.h> // For socket functions
#include <unistd.h>     // For close

// FIX
#include "christine.pb.h"
#include "hytech.pb.h"
/**
 * @brief Class Server
 * 
 * Header file for the server driver
 */
class Server {
public:
    Server(const std::string& server_ip, uint16_t server_port);
    ~Server();

    bool SendMessage(const hytech::Server& message);
    bool ReceiveMessage(christine::Client& message);

private:
    int _sock;
    sockaddr_in _server_addr;
    sockaddr_in _client_addr; 
    // Analyze why we make a specific sockaddr_in for client & their purposes
    // Compared to client_driver
    static const int _BUFFER_SIZE = 1024;
};

#endif // SERVER_H
