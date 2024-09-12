#ifndef UDP_SOCKET_H
#define UDP_SOCKET_H

#include <string>
#include <arpa/inet.h>

class UDPSocket {
public:
    UDPSocket();
    ~UDPSocket();

    bool bindSocket(const std::string& ip, int port);
    ssize_t sendTo(const std::string& message, const std::string& ip, int port);
    ssize_t receiveFrom(std::string& message, std::string& senderIp, int& senderPort);

private:
    int sockfd;
    struct sockaddr_in localAddr;
    struct sockaddr_in remoteAddr;

    void closeSocket();
};

#endif // UDP_SOCKET_H
