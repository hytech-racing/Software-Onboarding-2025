#include "info.pb.h"

#pragma once

class mainServer {
    public:
        mainServer();
        bool send(info::data message, int port);
        void receive(std::string& message);
        void close();
};

