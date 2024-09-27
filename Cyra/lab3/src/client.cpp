#include <udp_socket.h>
#include <message.pb.h>
#include <iostream>
#include <string>

int main() {
    UdpSocket client(0);  // Client socket with automatic port assignment

    std::string client_name;
    std::string client_message;

    // Get client details from the user
    std::cout << "Enter your name: ";
    std::getline(std::cin, client_name);

    std::cout << "Enter your message: ";
    std::getline(std::cin, client_message);

    // Create and serialize a Protobuf message
    carmessage::CarMsg message;
    message.set_sender_name(client_name);  // Set the client's name
    message.set_message(client_message);  // Set the client's message
    std::string serialized_message = message.SerializeAsString();

    // Send the serialized message to the server
    client.sendMessage(serialized_message, "192.168.203.1", 1173);  // Use loopback if on the same machine

    // Wait for a response from the server
    std::string received_data;
    std::string sender_ip;
    int sender_port;
    client.receiveMessage(received_data, sender_ip, sender_port);

    // Deserialize the server's response
    carmessage::CarMsg response_message;
    if (response_message.ParseFromString(received_data)) {
        std::cout << "Server response: " << response_message.message() << std::endl;
    } else {
        std::cerr << "Failed to parse the server's response." << std::endl;
    }

    return 0;
}
