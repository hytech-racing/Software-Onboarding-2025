// FIX

#include "client_driver.h" // Update include path
#include "server_driver.h"
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
        christine::Client receivedMessage;

        // Receive message from client
        if (server.ReceiveMessage(receivedMessage)) {
            // Prepare and send a response to client
            hytech::Server responseMessage;
            responseMessage.set_sender_name("HyTech");
            responseMessage.set_message("Hello from the Car!");
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
