#include <udp_socket.h>
#include <message.pb.h>
#include <iostream>
#include <string>

using carmessage::CarMsg;

int main() {
    UdpSocket server(1173);  // Server bound to port 1173

    while (true) {
        std::string received_data;
        std::string sender_ip;
        int sender_port;

        // Wait for a message from the client
        server.receiveMessage(received_data, sender_ip, sender_port);

        // Deserialize the received Protobuf message
        CarMsg client_message;
        if (client_message.ParseFromString(received_data)) {
            std::cout << "Received message from " << client_message.sender_name()
                      << " (" << sender_ip << ":" << sender_port << ") -> "
                      << client_message.message() << std::endl;
        } else {
            std::cerr << "Failed to parse the received message." << std::endl;
            continue;  // Skip to the next iteration of the loop
        }

        // Create a response message
        std::string server_response = "Acknowledged.";

        CarMsg response_message;
        response_message.set_sender_name("Server");  // Set the server name
        response_message.set_message(server_response);  // Set the response message

        // Serialize the response message
        std::string serialized_message = response_message.SerializeAsString();

        // Send the response back to the client
        server.sendMessage(serialized_message, sender_ip, sender_port);
    }

    return 0;
}
