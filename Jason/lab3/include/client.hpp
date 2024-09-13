#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <arpa/inet.h>  // For sockaddr_in
#include <sys/socket.h> // For socket functions
#include <unistd.h>     // For close

#include "src/proto/message.pb.h"

class Client {
public:
    Client(const std::string& server_ip, uint16_t server_port);
    ~Client();

    bool SendMessage(const message::data& message);
    bool ReceiveMessage(message::data& message);

private:
    int _sockfd;
    sockaddr_in _server_addr;
    static const int _BUFFER_SIZE = 1024;
};

#endif // CLIENT_H