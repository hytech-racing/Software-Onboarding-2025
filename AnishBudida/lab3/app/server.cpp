#include "info.pb.h"
#include "mainFile.hpp"

int main() {
    mainServer mainServer("127.0.0.1", 13337);

    while (true) {
        info::data message;
        if (mainServer.receive(message)) {
            std::cout << "The message received: " << message.text() << std::endl;
            message.set_text("helloBack");
            message.set_sender_name("newServer");
            mainServer.send(message, 1);
        }
    }

    mainServer.close();
}
