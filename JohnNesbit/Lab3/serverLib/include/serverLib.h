#ifndef HelloWorld_H // include guard
#define HelloWorld_H

#include "telemetry.pb.h"
#include <iostream>
#include <string> 
#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>	/* for fprintf */
#include <string.h>	/* for memcpy */
#include <netinet/in.h>	


namespace N
{
    class serverLib
    {
    public:
        static int createBindSocket(int port);
        static protoFirst::Telemetry serverListenSocket(int socket, sockaddr_in* remaddr);
		static protoFirst::Telemetry clientListenSocket(int socket);
		static int serverSendPacket(protoFirst::Telemetry tel, sockaddr_in remaddr, int fd);
        static int clientSendPacket(protoFirst::Telemetry tel, int port, const char* ip_address, int clientSocket);
    };

}

#endif