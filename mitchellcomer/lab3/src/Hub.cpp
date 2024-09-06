#include <iostream>
#include <cstring>
#include "Hub.hpp"

Hub::Hub(std::string server_ip, uint16_t port){
    if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
	    std::cout << "socket not work!?" << std::endl;
        exit(1);
    }

    memset((char *)&sAddr, 0, sizeof(sAddr));
    sAddr.sin_family = AF_INET;
    sAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    sAddr.sin_port = htons(port);
}

bool Hub::send(data::info message, bool returning){
    std::string serialized;
    if(!message.SerializeToString(&serialized)){
        std::cout << "no serialize!?" << std::endl;
        return false;
    }

    if(returning){
        if (sendto(fd, serialized.data(), serialized.size(), 0, (struct sockaddr *)&remaddr, sizeof(sAddr)) < 0){
            std::cout << "no send!?" << std::endl;
            return false;
        }
    }
    else{
        if (sendto(fd, serialized.data(), serialized.size(), 0, (struct sockaddr *)&sAddr, sizeof(sAddr)) < 0){
            std::cout << "no send!?" << std::endl;
            return false;
        }
    }
    
    return true;
}

bool Hub::receive(data::info& message){
    const int bufferSize = 1024;
     /* remote address */
    socklen_t addrlen = sizeof(remaddr);            /* length of addresses */

    unsigned char buf[bufferSize];     /* receive buffer */

    int recvlen = recvfrom(fd, buf, bufferSize, 0, (struct sockaddr *)&remaddr, &addrlen);
    if(recvlen < 0){
        std::cout << "no receive!?" << std::endl;
        return false;
    } else {
        std::cout << "recvd data "<< recvlen <<std::endl;
    }

    if (!message.ParseFromArray(buf, recvlen)) {
        std::cout << "Failed to parse message" << std::endl;
        return false;
    }

    return true;
}

void Hub::close(){
    ::close(fd);
}

bool Hub::bind(){
    if (::bind(fd, (struct sockaddr *)&sAddr, sizeof(sAddr)) < 0) {
        std::cout << "bind not work!?" << std::endl;
	    return false;
    }

    return true;
}
