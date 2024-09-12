#include "UDPSocket.hpp"
#include <iostream>
#include <string>

int main() {
    UDPSocket udpSocket;

    // Define server IP and port
    std::string serverIp = "127.0.0.1";
    int serverPort = 8080;

    // Send the message to the server
    udpSocket.sendTo("Test Message", serverIp, serverPort);
    std::cout << "Sent message to server: \n";

    // Receive the response from the server
    std::string responseMessage, serverIpReceived;
    int serverPortReceived;
    ssize_t bytesReceived = udpSocket.receiveFrom(responseMessage, serverIpReceived, serverPortReceived);

    if (bytesReceived > 0) {
        std::cout << "Received message from " << serverIp << ":" << serverPort << ": " << responseMessage << "\n";
    } else {
        std::cerr << "Error receiving message from server\n";
    }

    return 0;
}
