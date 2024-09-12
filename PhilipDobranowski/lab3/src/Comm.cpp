#include <Comm.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <message.pb.h>

Comm::Comm(std::string ip, int port)
{
    this->port = port;
    this->ip = ip.data();

    if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("cannot create socket");
        exit(1);
    }

    memset((char *)&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    inet_pton(AF_INET, this->ip, &serverAddr.sin_addr);
    serverAddr.sin_port = htons(port);
}

void Comm::bind()
{
    if (::bind(fd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("bind failed");
        exit(1);
    }
}

void Comm::send(std::string msg, int from)
{
    if (from == 0) {
        if (sendto(fd, msg.data(), msg.length(), 0, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
            perror("sendto failed");
            exit(1);
        }
    } else {
        if (sendto(fd, msg.data(), msg.length(), 0, (struct sockaddr *)&remoteAddr, sizeof(remoteAddr)) < 0) {
            perror("sendto failed");
            exit(1);
        }
    }
}

std::string Comm::recv()
{
    char msg[1024];
    int bufferSize = 1024;

    socklen_t len = sizeof(remoteAddr);
    if (recvfrom(fd, msg, bufferSize, 0, (struct sockaddr *)&remoteAddr, &len) < 0) {
        perror("recvfrom failed");
        exit(1);
    }

    std::string ret = msg;
    return ret;
}

void Comm::close()
{
    ::close(fd);
}