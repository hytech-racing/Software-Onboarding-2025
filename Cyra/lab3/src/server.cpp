#include "udp_socket.h"
#include "message.pb.h"
#include <iostream>
#include <string>

using carmessage::CarMsg;  

int main() {
    UdpSocket server(1173); 

    while (true) { 
        std::string received_data;
        std::string sender_ip;
        int sender_port;

       
        server.receiveMessage(received_data, sender_ip, sender_port);
        
     
        SimpleMessage client_message;
        if (client_message.ParseFromString(received_data)) {
            std::cout << "Received message from " << client_message.sender_name() << " (" 
                      << sender_ip << ":" << sender_port << ") -> " 
                      << client_message.text() << std::endl;
        } else {
            std::cout << "Failed to parse the received message." << std::endl;
            continue;  
        }

 
        std::string server_response = "Acknowledged.";


        SimpleMessage message;
        message.set_sender_name("Server");  
        message.set_text(server_response);
        std::string serialized_message = message.SerializeAsString();

t
        server.sendMessage(serialized_message, sender_ip, sender_port);
    }

    return 0;
}
