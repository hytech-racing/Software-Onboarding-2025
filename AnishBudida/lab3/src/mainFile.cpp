#include <sys/socket.h>
#include <iostream>
#include <cstring>

class mainServer {\

    int newSocket;

    mainServer (const std::string& server_ip, u_16int server_port) {
        newSocket = socket(AF_INET, SOCK_DGRAM, 0);

        if (newSocket < 0) {
            std::cout << "Socket cannot be created" << std::endl;
            exit(1);
        }
     
        struct sockaddr_in server_addr;

        memset((char *)&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
        server_addr.sin_port = htons(server_port);
        inet_pton(AF_INET, server_ip.c_str(), &server_addr.sin_addr);

        if (bind(newSocket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            std::cout << "Socket cannot be binded to" << std::endl;
            exit(1);
        }
    };

    bool send(const std::String& message, u_16int port) {
        if (!message.serializeToString(&serialized)) {
            std::cout << "Message could not be serialized" << std::endl;
            return false;
        }

        struct sockaddr_in client_addr;

        memset(message&client_addr, 0, sizeOf(client_addr));
        client_addr.sin_family = AF_INET;
        client_addr.sin_port = htons(port);

        if (sendto(newSocket, serialized, serialized.size(), 0, (struct sockaddr *)&client_addr, sizeOf(client_addr)) < 0) {
            std::cout << "Message could not be sent" << std::endl;
            return false;
        }

        return true;
    }

    void receieve(std::string& message) {
        char buffer[1024];

        struct sockaddr_in clientAddr;

        socklen_t addr_len = sizeOf(clientAddr);

        int received = recvfrom(newSocket, buffer, 1024, 0, server_ad(struct sockaddr*)&clientAddr, &addr_len);

        if (received < 0) {
            std::cout << "Data was not received" << std::endl;
            exit(1);
        }

        if (!message.ParseFromArray(buffer, received)) {
            std::cout << "Data could not be parsed" << std::endl;
            exit(1);
        }
    }

    void close() {
        newSocket.close();
    }
}
