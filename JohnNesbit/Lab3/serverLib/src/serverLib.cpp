#include "serverLib.h"
#include "telemetry.pb.h"
#include <string> 
#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>	/* for fprintf */
#include <string.h>	/* for memcpy */
#include <netinet/in.h>	
#include <arpa/inet.h>

using namespace N;
using namespace std;

namespace N{ 
int serverLib::createBindSocket(int port){
	int fd;
	if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
		perror("cannot create socket");
		return 0;
	}
	
	// struct containing address information
	struct sockaddr_in myaddr;
	
	// clear any uncleared values in myaddr mem location 
	memset((char *)&myaddr, 0, sizeof(myaddr));
	
	// set struct values to UDP family, port and address from parameterss. Print Address, port
	myaddr.sin_family = AF_INET;
	myaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	myaddr.sin_port = htons(port);
	
    char ip_str[20];
    inet_ntop(AF_INET, &myaddr.sin_addr.s_addr, ip_str, sizeof(ip_str));
    printf("IP address: %s, Port: %d\n", ip_str, myaddr.sin_port);

	// bind port and address to our socket memory location
	if (bind(fd, (struct sockaddr *)&myaddr, sizeof(myaddr)) < 0) {
		perror("bind failed");
		return 0;
	}
	printf("Created socket at %d \n", fd);
	return fd;
	
}


protoFirst::Telemetry serverLib::serverListenSocket(int socket, sockaddr_in* remaddr){
	protoFirst::Telemetry t;
	
	// loop until message, return deserialized telemetry obj
	// pointer to remaddr gets filled by a sockaddr_in struct by recvfrom
	char buf[1024]; // unfortunately, I dont know how big the protobuf packets are, could update with printf
	int recvlen;
	socklen_t addrlen = sizeof(*remaddr);
	while(true) {
		recvlen = recvfrom(socket, buf, sizeof(buf), 0, (struct sockaddr *)remaddr, &addrlen);
		printf("received %d bytes\n", recvlen);
		if (recvlen > 0) {
				buf[recvlen] = 0;
				t.ParseFromArray(buf, recvlen);
				return t;
		}
	}
}


protoFirst::Telemetry serverLib::clientListenSocket(int socket){
	protoFirst::Telemetry t;
	
	// loop until message, return deserialized telemetry obj
	// pointer to sender_addr gets filled by a sockaddr_in struct by recvfrom
	char buf[1024]; // unfortunately, I dont know how big the protobuf packets are, could update with printf
	int recvlen;
	while(true) {
		recvlen = recvfrom(socket, buf, sizeof(buf), 0, nullptr, nullptr);
		printf("received %d bytes\n", recvlen);
		if (recvlen > 0) {
				buf[recvlen] = 0;
				t.ParseFromArray(buf, recvlen);
				return t;
		}
	}
}

int serverLib::clientSendPacket(protoFirst::Telemetry tel, int port, const char* ip_address, int clientSocket){
	struct sockaddr_in servaddr;
	socklen_t addrlen = sizeof(servaddr);
	
    memset((char*)&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);

    /* convert the IP address string to binary form */
    if (inet_pton(AF_INET, ip_address, &servaddr.sin_addr) <= 0) {
        std::cerr << "Invalid IP address: " << ip_address << std::endl;
        return -1;
    }

	std::string serialized_msg;
	if (!tel.SerializeToString(&serialized_msg)) {
		std::cerr << "Failed to serialize message." << std::endl;
		return -1;
	}

	/* send a message to the server */	
	if (sendto(clientSocket, serialized_msg.data(), serialized_msg.size(), 0, (struct sockaddr *)&servaddr, addrlen) < 0) {
		perror("sendto failed");
		return -1;
	}
	return 1;
	
}

int serverLib::serverSendPacket(protoFirst::Telemetry tel, sockaddr_in remaddr, int fd){
	
	std::string serialized_msg;
	if (!tel.SerializeToString(&serialized_msg)) {
		std::cerr << "Failed to serialize message." << std::endl;
		return -1;
	}
	
	sendto(fd, serialized_msg.data(), serialized_msg.size(), 0, (struct sockaddr *)&remaddr, sizeof(remaddr));
	return 0;
}

}