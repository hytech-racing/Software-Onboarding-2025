#ifndef host_hpp
#define host_hpp

// OR use #ifndef/#define/#endif for manual guards

#include <string>       // For std::string
#include <stdexcept>    // For exception handling (if needed)
#include <sys/types.h>  // Socket-related types
#include <sys/socket.h> // Socket API
#include <netinet/in.h> // For struct sockaddr_in
#include <arpa/inet.h>  // For inet_pton() and inet_ntop()
#include <unistd.h>     // For close() and other system calls
#include "data.pb.h"    // Protobuf generated header, use "message.pb.h" if that's the correct one

class Host
{
private:
    int fd;
    struct sockaddr_in remAddr, servAddr;

public:
    Host(std::string ip, uint16_t udp_port);
    bool send(data::info msg, bool returnV);
    bool receive(data::info &msg);
    bool bind();
    void close();
};

#endif