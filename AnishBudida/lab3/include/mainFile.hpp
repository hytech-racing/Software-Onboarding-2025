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
        mainServer(const std::string server_ip, int port);
        bool send(info::data message, int port);
        bool receive(info::data message);
        void close();
};

