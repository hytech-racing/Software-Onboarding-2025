#include "UDPSocket.hpp"
#include <iostream>
#include <string>
#include "proto/message.pb.h"

int main() {
    UDPSocket udpSocket;

    // Bind the socket to a local IP and port
    if (!udpSocket.bindSocket("127.0.0.1", 8080)) {
        std::cerr << "Failed to bind socket\n";
        return -1;
    }

    while (true) {
        // Receive a message
        std::string serializedMessage, senderIp;
        int senderPort;
        ssize_t bytesReceived = udpSocket.receiveFrom(serializedMessage, senderIp, senderPort);

        if (bytesReceived > 0) {
            std::cout << "Received message from " << senderIp << ":" << senderPort << ": " << serializedMessage << "\n";
        } else {
            std::cerr << "Error receiving message\n";
        }
    }

    return 0;
}
