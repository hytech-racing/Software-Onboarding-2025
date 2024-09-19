#include <stdio.h>
#include <sys/socket.h>
#include <Comm.hpp>

class Comm
{
    public:
        Comm(std::string ip, int port);

        void close();
        bool send(char* msg, int len);
        bool recv(char* msg, int len);
        bool bind();
};