cmake_minimum_required(VERSION 3.10)
project(ProtoBufUDP)

find_package(Protobuf REQUIRED)
include_directories(${Protobuf_INCLUDE_DIRS} generated/)

# Add the udp_socket library
add_library(udp_socket src/udp_socket.cpp)

# Protobuf generated sources
set(PROTO_SRC generated/message.pb.cc)

# Add the server executable
add_executable(server src/server.cpp ${PROTO_SRC})
target_link_libraries(server udp_socket ${Protobuf_LIBRARIES})

# Add the client executable
add_executable(client src/client.cpp ${PROTO_SRC})
target_link_libraries(client udp_socket ${Protobuf_LIBRARIES})
