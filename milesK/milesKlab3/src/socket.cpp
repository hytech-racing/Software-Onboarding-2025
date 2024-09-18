#include <iostream>
#include <string>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

#define BUFFERSIZE 2048

class Socket {
    int port;
    int fd;

public:
    Socket (int port) {
        this->port = port;
        this->fd = socket(AF_INET, SOCK_DGRAM, 0);

        if (fd < 0) {
            std::cerr << "Failed to create socket\n";
            return 0;
        }

        struct sockaddr_in server_addr;
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = INADDR_ANY;
        server_addr.sin_port = htons(port);

        if (bind(fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            std::cerr << "Failed to bind socket\n";
            return 0;
        }
    }
    ~Socket() {
        close(fd);
    }

    void sendMsg (std::string& message, std::string& remoteIP, int& port) {
		struct sockaddr_in remoteAddr;
        // Populate remoteAddr
		memset((char*)&remoteAddr, 0, sizeof(remoteAddr));
		remoteAddr.sin_family = AF_INET;
		remoteAddr.sin_port = htons(port);
		inet_pton(AF_INET, remoteIP.c_str(), &remoteAddr.sin_addr);

        // Send msg
		if (sendto(this->fd, message.c_str(), message.length(), 0, (struct sockaddr*)&remoteAddr, sizeof(remoteAddr)) < 0) {
			std::cerr << "sendto failed" << std::endl;
			return;
		}
    }

    void getMsg (std::string& message, std::string& remoteIP, int& port) const {
        struct sockaddr_in localAddr;
        struct sockaddr_in remoteAddr;
        socklen_t addrlen = sizeof(remoteAddr);
        unsigned char buf[BUFFERSIZE] = "";


        // bind the socket to any valid IP address and a specific port
        memset((char*)&localAddr, 0, sizeof(localAddr));
        localAddr.sin_family = AF_INET;
        localAddr.sin_addr.s_addr = htonl(INADDR_ANY);
        localAddr.sin_port = htons(port);

        if (bind(this->fd, (struct sockaddr*)&localAddr, sizeof(localAddr)) < 0 {
            perror("bind failed");
            return "";
        }

        // Get the msg 
        int recvlen = recvfrom(this->fd, buf, BUFFERSIZE, 0, (struct sockaddr*)&remoteAddr, &addrlen);
        if (recvlen > 0) {
            buf[recvlen] = '\0';
            message = std::string(buf);
        }
        else {
            message = "";
        }
    }
}
