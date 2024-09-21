#include <iostream>
#include <unistd.h>
#include <limits.h>
#include "../include/info.pb.h" // TODO
#include "../include/socket.hpp" // TODO

#define UDP_PORT 10024


int main (void) {
    const std::string REMOTE_ADDR_STR = "127.0.0.1";

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
    std::string name = std::string(username) + "@" + std::string(hostname);

    // get message
    std::string message = "fuc";

    // serialize message into protobuf shit
    info::generic_message gMsg;
    gMsg.set_authorname(name);
    gMsg.set_contents(message);
    std::string serializedMsg = gMsg.SerializeAsString();
  
    // Send the message to the server
    client.sendMsg(serializedMsg, REMOTE_ADDR_STR, UDP_PORT);

    std::string receivedData;
    std::string senderIP;
    int senderPort;

    // Now pass the received data, sender_ip, and sender_port to the receiveMessage function
    client.getMsg(receivedData, senderIP, senderPort);

    // Deserialize the received message
    info::generic_message receivedMsg;
    if (receivedMsg.ParseFromString(receivedData)) {
        std::cout << "Server message: " << receivedMsg.contents() << std::endl;
    } else {
        std::cerr << "Failed to parse the message from the server." << std::endl;
    }

    return 0;
}
