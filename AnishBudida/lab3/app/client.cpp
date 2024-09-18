#include "info.pb.h"
#include "mainFile.hpp"

int main() {
    mainServer client("127.0.0.1", 8080);

    info::data message;

    client.send(message, 0);

    while(!(client.receive(message)));

    std::cout << "Message received: " << message << std::endl;

    client.close();   
}
