#ifndef UDP_SOCKET_H
#define UDP_SOCKET_H

#include <string>

class UdpSocket {
public:
    UdpSocket(int port); 
    ~UdpSocket(); 

    void sendMessage(const std::string& message, const std::string& ipAddress, int port);
    void receiveMessage(std::string& message, std::string& sender_ip, int& port);

private:
    int socket_fd;
    int port;
};

#endif
