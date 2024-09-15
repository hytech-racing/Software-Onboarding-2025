#include "info.pb.h"
#include "mainFile.hpp"

int main() {
    mainServer mainServer("0.0.0.0", 8000);

    while (true) {
        info::data message;
        if (mainServer.receive(message)) {
            std::cout << "The message received: " << message << std::endl;
            message.set_sender_name("newServer");
            mainServer.send(message, 0);
        }
    }

    mainServer.close();
}
