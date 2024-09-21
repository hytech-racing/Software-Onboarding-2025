#include <iostream>
#include <string>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

#ifndef SOCKET_HPP

#define BUFFERSIZE 2048

class Socket {
    int port;
    int fd;

public:
    Socket (int port);
    Socket (int port, bool);
    ~Socket();
    void sendMsg (std::string message, std::string remoteIP, int port);
    void getMsg (std::string& message, std::string& remoteIP, int& port);
};
#endif

