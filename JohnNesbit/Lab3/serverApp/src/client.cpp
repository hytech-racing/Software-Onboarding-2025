#include "serverLib.h"
#include "telemetry.pb.h"
#include <iostream>
#include <string> 
#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>	/* for fprintf */
#include <string.h>	/* for memcpy */
#include <netinet/in.h>	

using namespace N;
using namespace std;
using namespace protoFirst;

int main()
{	
	serverLib s;
	// ask for our port and IP
	 string port;
	 string Adress;
	 std::cout << "Enter your desired port for the client: ";
	 std::cin >> port; 
	 
     // create client socket
	 int socket = s.createBindSocket(std::stoi(port));
	 
	 // ask for the port and IP
	 std::cout << "Enter the server's port: ";
	 std::cin >> port; 
	 
	 std::cout << "Enter the server IP Adress: ";
	 std::cin >> Adress; 
	 const char* adData = Adress.data();
	 
	 
	 // create message
	 Telemetry tel;
	 tel.set_sender_name("JahnNessy");
	 tel.set_x(5);
	 tel.set_y(10);
	 
	 // send a message
	 s.clientSendPacket(tel, std::stoi(port), adData, socket);
	 
	 // listen
	 tel = s.clientListenSocket(socket);
	 
	 // print message
	 std::cout << tel.sender_name();
	 close(socket);

     return 0;
}