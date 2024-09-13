#include "client.hpp" 
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
    message::data message;
    message.set_sender_name("Msg From Client");
    
    std::string input;
    std::cout << "Press Enter to send a message: ";
    std::getline(std::cin, input);

    while (true) {
        std::cout << "Press Enter to send a message (or type -1 to exit): ";
        std::getline(std::cin, input);

        // If the user enters -1, break the loop and exit
        if (input == "-1") {
            std::cout << "Exiting program..." << std::endl;
            break;
        }

        // If Enter is pressed (input is empty), send the message
        if (input.empty()) {
            // Send the message
            if (client.SendMessage(message)) {
                std::cout << "Message sent successfully" << std::endl;
            } else {
                std::cerr << "Failed to send message" << std::endl;
            }

            // Receive and print the response
            message::data responseMessage;
            if (client.ReceiveMessage(responseMessage)) {
                std::cout << "Received response from server" << std::endl;
            } else {
                std::cerr << "Failed to receive response" << std::endl;
            }
        } else {
            std::cout << "No message sent." << std::endl;
        }
    }

    return 0;
}