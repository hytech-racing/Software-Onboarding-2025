#include "info.pb.h"
#include "mainFile.hpp"

int main() {
    mainServer client("127.0.0.1", 1337);

    info::data message;

    message.set_text("hello to the racing world");
    message.set_sender_name("client");

    client.send(message, 0);

    while(!(client.receive(message)));

    std::cout << "Message received: " << message.text() << std::endl;

    client.close();   
}
