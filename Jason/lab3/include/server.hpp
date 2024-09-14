#ifndef SERVER_H
#define SERVER_H

#include <string>
#include <arpa/inet.h>  // For sockaddr_in
#include <sys/socket.h> // For socket functions
#include <unistd.h>     // For close

#include "message.pb.h"

class Server {
public:
    Server(const std::string& server_ip, uint16_t server_port);
    ~Server();

    bool SendMessage(const message::data& message);
    bool ReceiveMessage(message::data& message);

private:
    int _sock;
    sockaddr_in _server_addr;
    sockaddr_in _client_addr; 
    static const int _BUFFER_SIZE = 1024;
};

#endif // SERVER_H