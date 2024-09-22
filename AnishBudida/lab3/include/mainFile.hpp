#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdexcept>
#include "info.pb.h"

#pragma once

class mainServer {
    public:
        int newSocket;
        struct sockaddr_in server_addr, rem_addr;
        mainServer(const std::string server_ip, int port);
        bool send(info::data message, int backToServer);
        bool receive(info::data message);
        void close();
};

