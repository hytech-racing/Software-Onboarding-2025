#include "udp_socket.h"
#include "message.pb.h"  // Include the generated Protobuf header
#include <iostream>

int main() {
    // Create the server socket and bind to port 1173
    UdpSocket server(1173);
    
    std::cout << "Server is listening on port 1173..." << std::endl;

    while (true) {
        std::string received_data;
        std::string sender_ip;
        int sender_port;

        // Receive a message from a client
        server.receiveMessage(received_data, sender_ip, sender_port);

        // Deserialize the received message
        example::SimpleMessage received_message;
        if (received_message.ParseFromString(received_data)) {
            std::cout << "Received message from " << sender_ip << ":" << sender_port << std::endl;
            std::cout << "Sender: " << received_message.sender_name() << std::endl;
            std::cout << "Message: " << received_message.text() << std::endl;
        } else {
            std::cerr << "Failed to parse the received message." << std::endl;
            continue;
        }

        // Create a response message
        example::SimpleMessage response_message;
        response_message.set_sender_name("UDP_Server");  // Server's name
        response_message.set_text("Message received successfully!");

        // Serialize the response
        std::string serialized_response;
        response_message.SerializeToString(&serialized_response);

        // Send the response back to the client
        server.sendMessage(serialized_response, sender_ip, sender_port);
        std::cout << "Response sent to " << sender_ip << ":" << sender_port << std::endl;
    }

    return 0;
}
