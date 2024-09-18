#include <iostream>
#include <unistd.h>
#include <limits.h>
#include "info.pb.h"

#define UDP_PORT 1173
#define REMOTE_ADDR_STR "127.0.0.1"

int main (void) {
    // assigning the port to 0 here indicates that
    // we are delegating the assignment of the port
    // to the OS probably; the port will be assigned
    // automatically to some ephermeral port
    Socket client(0);

    // make apparent name user@host
    char hostname[HOST_NAME_MAX];
    char username[LOGIN_NAME_MAX];
    gethostname(hostname, HOST_NAME_MAX);
    getlogin_r(username, LOGIN_NAME_MAX);
    std::string name = std::string(username << "@" << hostname);

    // get message
    std::string message;
    std::cout << "MESSAGE:\n";
    std::getline(std::cin, message);

    // serialize message into protobuf shit
    info::generic_message gMsg;
    gMsg.set_sender_name(name);
    gMsg.set_text(message);
    std::string serializedMsg = gMsg.SerializeAsString();
  
    // Send the message to the server
    client.sendMessage(serializedMsg, REMOTE_ADDR_STR, UDP_PORT);

    std::string receivedData;
    std::string senderIP;
    int sender_port;

    // Now pass the received data, sender_ip, and sender_port to the receiveMessage function
    client.receiveMessage(receivedData, senderIP, sender_port);

    // Deserialize the received message
    info::generic_message receivedMsg;
    if (receivedMsg.ParseFromString(receivedData)) {
        std::cout << "Server message: " << receivedMsg.text() << std::endl;
    } else {
        std::cerr << "Failed to parse the message from the server." << std::endl;
    }

    return 0;
}
