#include <iostream>
#include "Host.hpp"
#include "data.pb.h"

int main()
{
    Host host("100.66.8.98", 1153);
    data::info msg;
    msg.set_sender_name("client");

    host.send(msg, false);

    while (!host.receive(msg))
        ;

    std::cout << msg.sender_name() << std::endl;

    host.close();

    return 0;
}