#ifndef hub_hpp
#define hub_hpp

#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdexcept>
#include "data.pb.h"

class Hub {
private:
    int fd;
    struct sockaddr_in sAddr;
    struct sockaddr_in remaddr;

public:
    Hub(std::string server_ip, uint16_t port);

    void close();
    bool send(data::info message, bool returning);
    bool receive(data::info& message);
    bool bind();
};

#endif