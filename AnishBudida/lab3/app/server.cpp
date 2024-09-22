#include "info.pb.h"
#include "mainFile.hpp"

int main() {
    mainServer mainServer("127.0.0.1", 1338);
    mainServer.bind();

    while (true) {
        info::data message = mainServer.receive();
        std::cout << "The message received from " << message.sender_name() << ": " << message.text() << std::endl;
        message.set_text("helloBack");
        message.set_sender_name("server");
        mainServer.send(message, 1);
    }

    mainServer.close();
}
