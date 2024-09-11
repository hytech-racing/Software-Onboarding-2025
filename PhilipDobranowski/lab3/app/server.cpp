#include <stdio.h>
#include <Comm.hpp>
#include <message.pb.h>

int main()
{
    Comm comm("127.0.0.1", 13337);
    comm.bind();
    
    lab3Proto::SimpleMessage msg;
    
    std::string buf = comm.recv();
    msg.ParseFromString(buf);
    std::cout << msg.sender_name() << " sent: " << msg.message() << std::endl;

    msg.set_sender_name("Server");
    msg.set_message("Server received your message of \"" + msg.message() + "\"!");
    std::string serialized_message;
    msg.SerializeToString(&serialized_message);
    comm.send(serialized_message, 1);
}