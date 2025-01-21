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
	
	 // ask for our port and IP
	 string port;
	 string Adress;
	 std::cout << "Enter your desired port for the server: ";
	 std::cin >> port; 
	 
	 std::cout << "Enter the server IP Adress: ";
	 std::cin >> Adress; 
	 const char* adData = Adress.data();
	 
     // create server socket
	 int socket = serverLib::createBindSocket(std::stoi(port));
	
	 // listen and record the client sender into remaddr
	 struct sockaddr_in remaddr;
	 Telemetry tel = serverLib::serverListenSocket(socket, &remaddr);
	 
	 // print message
	 std::cout << tel.sender_name();
     printf("\n From client with the port: %d\n", remaddr.sin_port);
	 
	 std::cout << "Send a message with the name: ";
	 std::cin >> Adress; 
	 	 
	 // send message back
	 Telemetry tel2;
	 tel2.set_sender_name(Adress);
	 tel2.set_x(3);
	 tel2.set_y(0);
	 
	 serverLib::serverSendPacket(tel2, remaddr, socket);
	 close(socket);

     return 0;
}