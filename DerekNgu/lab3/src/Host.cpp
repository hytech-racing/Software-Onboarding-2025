#include <iostream>
#include <cstring>
#include <data.pb.h>
#include "Host.hpp"

Host::Host(std::string ip, uint16_t udp_port)
{
    if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        std::cout << "socket not work!?" << std::endl;
        exit(1);
    }

    memset((char *)&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;

    inet_pton(AF_INET, ip.c_str(), &servAddr.sin_addr);
    servAddr.sin_port = htons(udp_port);
}

bool Host::send(data::info msg, bool returnV)
{
    std::string serialized;
    if (!msg.SerializeToString(&serialized))
    {
        std::cout << "no serialize!?" << std::endl;
        return false;
    }

    if (returnV)
    {
        if (sendto(fd, serialized.data(), serialized.size(), 0, (struct sockaddr *)&remAddr, sizeof(servAddr)) < 0)
        {
            std::cout << "no send!?" << std::endl;
            return false;
        }
    }
    else
    {
        if (sendto(fd, serialized.data(), serialized.size(), 0, (struct sockaddr *)&servAddr, sizeof(servAddr)) < 0)
        {
            std::cout << "no send!?" << std::endl;
            return false;
        }
    }

    return true;
}

bool Host::receive(data::info &msg)
{
    const int bufferSize = 1024;
    /* remote address */
    socklen_t addrlen = sizeof(remAddr); /* length of addresses */

    unsigned char buf[bufferSize]; /* receive buffer */

    int recvlen = recvfrom(fd, buf, bufferSize, 0, (struct sockaddr *)&remAddr, &addrlen);
    if (recvlen < 0)
    {
        std::cout << "no receive!?" << std::endl;
        return false;
    }
    else
    {
        std::cout << "recvd data " << recvlen << std::endl;
    }

    if (!msg.ParseFromArray(buf, recvlen))
    {
        std::cout << "Failed to parse message" << std::endl;
        return false;
    }

    return true;
}

void Host::close()
{
    ::close(fd);
}

bool Host::bind()
{
    if (::bind(fd, (struct sockaddr *)&servAddr, sizeof(servAddr)) < 0)
    {
        std::cout << "bind not work!?" << std::endl;
        return false;
    }

    return true;
}
