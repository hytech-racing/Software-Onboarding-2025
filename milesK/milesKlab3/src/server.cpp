#include "../include/socket.hpp" // TODO
#include "../include/info.pb.h" // TODO
#include <iostream>
#include <string>

#define UDP_PORT 10024

int main() {
    Socket server(1173, true);  // Create a UDP socket on port 8080

    while (true) {  // Infinite loop to keep the server running
        std::string received_data;
        std::string sender_ip;
        int sender_port;

        // Receive a message from the client
        server.getMsg(received_data, sender_ip, sender_port);
        
        // Deserialize the received message
        info::generic_message client_message;
        if (client_message.ParseFromString(received_data)) {
            if (received_data.length() > 0) {
                std::cout << "Received message from " << client_message.authorname() << " (IP: " 
                      << sender_ip << ":" << sender_port << ") -> " 
                      << client_message.contents() << std::endl;

                // Allow input of the server's response message
                std::string server_response = "Acknowledged.";

                // Prepare a response
                info::generic_message message;
                message.set_authorname("Server");  // Server's name
                message.set_contents(server_response);
                std::string serialized_message = message.SerializeAsString();

                // Send the response back to the client
                server.sendMsg(serialized_message, sender_ip, sender_port);
            }
        } else {
            std::cout << "Failed to parse the received message." << std::endl;
            continue;  // Skip to the next iteration of the loop
        }

    }

    return 0;
}
