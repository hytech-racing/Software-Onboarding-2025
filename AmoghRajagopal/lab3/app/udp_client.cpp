#include "../src/udp_socket.h"
#include "../generated/message.pb.h"  
#include <iostream>
#include <string>

int main() {
    // Create our UDP client socket and assign to some free port
    UdpSocket client(0);  

    std::string client_name = "Client_A";  
    std::string client_message = "Hello, UDP Server!";

    //Create and serialize message
    example::SimpleMessage message;
    message.set_sender_name(client_name);
    message.set_text(client_message);
    std::string serialized_message = message.SerializeAsString();

    // Send message to server
    client.sendMessage(serialized_message, "127.0.0.1", 1173);
    std::cout << "Message sent to server." << std::endl;

    //Get response from server
    std::string received_data;
    std::string sender_ip;
    int sender_port;
    client.receiveMessage(received_data, sender_ip, sender_port);

    //Deserialize received message
    example::SimpleMessage received_message;
    if (received_message.ParseFromString(received_data)) {
        std::cout << "Response from server: " << received_message.text() << std::endl;
    } else {
        std::cerr << "Failed to parse the response from the server." << std::endl;
    }

    return 0;
}
