#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <message.pb.h>

class Comm
{
    private:
        int fd;
        struct sockaddr_in serverAddr, remoteAddr;

        int port;
        char* ip;
    public:
        Comm(std::string ip, int port);
        void close();
        void send(std::string msg, int from);
        std::string recv();
        void bind();
};