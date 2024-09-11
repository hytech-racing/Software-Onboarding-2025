#include <stdio.h>
#include <Comm.hpp>
#include <message.pb.h>

int main()
{
    Comm comm("127.0.0.1", 13337);

    std::string buf;
    lab3Proto::SimpleMessage msg;

    std::cout << "Enter your message: ";
    std::cin >> buf;
    msg.set_sender_name("Client");
    msg.set_message(buf);

    std::string serialized_message;
    msg.SerializeToString(&serialized_message);
    comm.send(serialized_message, 0);

    buf = comm.recv();
    msg.ParseFromString(buf);
    std::cout << msg.sender_name() << " sent: " << msg.message() << std::endl;
}