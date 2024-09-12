cmake_minimum_required(VERSION 3.10)
project(ProtoBufUDP)

find_package(Protobuf REQUIRED)

add_library(udp_socket src/udp_socket.cpp)

add_executable(server src/server.cpp generated/message.pb.cc)

target_link_libraries(server PRIVATE udp_socket protobuf::libprotobuf)

add_executable(client src/client.cpp generated/message.pb.cc)

target_link_libraries(client PRIVATE udp_socket protobuf::libprotobuf)

target_include_directories(server PRIVATE generated/)
target_include_directories(client PRIVATE generated/)

install(TARGETS server client DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
