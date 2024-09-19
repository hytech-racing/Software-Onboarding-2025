#include "info.pb.h"
#include "mainFile.hpp"

int main() {
    mainServer mainServer("127.0.0.1", 0);

    while (true) {
        info::data message;
        if (mainServer.receive(message)) {
            std::cout << "The message received: " << message.text() << std::endl;
            message.set_text("helloBack");
            message.set_sender_name("newServer");
            mainServer.send(message, 8080);
        }
    }

    mainServer.close();
}
