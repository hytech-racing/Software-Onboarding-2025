// FIX

#include "client_driver.h" // Update include path
#include "server_driver.h"
#include <iostream>

/**
 * @brief Executable that initiates Client
 * 
 * This files boots up the Client
 */
int main() {
    // Initialize the client with server IP and port
    Client client("127.0.0.1", 8080); // Replace with the server's IP address AKA the car

    // Create and send a message with the input '1'
    christine::Client message;
    message.set_sender_name("Christine");
    message.set_message("Hello from the CHRISTINE!");
    
    std::string input;
    std::cout << "Enter '1' to send a message: ";
    std::getline(std::cin, input);

    if (input == "1") {
        // Send the message
        if (client.SendMessage(message)) {
            std::cout << "Message sent successfully" << std::endl;
        } else {
            std::cerr << "Failed to send message" << std::endl;
        }

        // Receive and print the response!
        hytech::Server responseMessage;
        if (client.ReceiveMessage(responseMessage)) {
            ;
        } else {
            std::cerr << "Failed to receive response" << std::endl;
        }
    } else {
        std::cout << "No message sent." << std::endl;
    }

    return 0;
}