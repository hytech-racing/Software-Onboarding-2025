#include "udp_socket.h"
#include "message.pb.h"
#include <iostream>
#include <string>

int main() {
    UdpSocket client(0);  // Create a UDP socket

    // Get the client's name and message from input
    std::string client_name;
    std::string client_message;

    std::cout << "Enter your name: ";
    std::getline(std::cin, client_name);

    std::cout << "Enter your message: ";
    std::getline(std::cin, client_message);

    // Prepare a message
    example::SimpleMessage message;
    message.set_sender_name(client_name);  // Set the client's name
    message.set_text(client_message);  // Set the client's message
    std::string serialized_message = message.SerializeAsString();
  
    // Send the message to the server
    client.sendMessage(serialized_message, "192.168.203.1", 1173);

    // Receive the response from the server
    std::string received_data;
    std::string sender_ip;
    int sender_port;

    // Now pass the received data, sender_ip, and sender_port to the receiveMessage function
    client.receiveMessage(received_data, sender_ip, sender_port);


    // Deserialize the received message
    example::SimpleMessage received_message;
    if (received_message.ParseFromString(received_data)) {
        std::cout << "Server message: " << received_message.text() << std::endl;
    } else {
        std::cerr << "Failed to parse the message from the server." << std::endl;
    }

    return 0;
}                                                                                                                     
 