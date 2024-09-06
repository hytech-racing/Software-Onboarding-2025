#include <iostream>
#include "Hub.hpp"
#include "data.pb.h"

int main(){
    Hub hub("127.0.0.1", 1153);
    data::info message;
    message.set_sender_name("client");

    hub.send(message, false);

    while(!hub.receive(message));

    std::cout << message.sender_name() << std::endl;

    hub.close();

    return 0;
}