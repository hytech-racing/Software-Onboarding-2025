#include "client.hpp" // Update include path
#include "server.hpp"
#include <iostream>

/**
 * @brief Executable that initiates Server
 * 
 * This files boots up the Server
 */
int main() {
    // Initiate Server
    Server server("0.0.0.0", 8080);

    std::cout << "Server is running and listening on port 8080..." << std::endl;
    // Be on the constant lookout for messages
    while (true) {
        message::data receivedMessage;

        // Receive message from client
        if (server.ReceiveMessage(receivedMessage)) {
            // Prepare and send a response to client
            message::data responseMessage;
            responseMessage.set_sender_name("Message from Server");
            // Send message
            if (server.SendMessage(responseMessage)) {
                std::cout << "Response sent successfully" << std::endl;
            } else {
                std::cerr << "Failed to send response" << std::endl;
            }
        } else {
            std::cerr << "Failed to receive message" << std::endl;
        }
    }

    return 0;
}