cmake_minimum_required(VERSION 3.10)
project(HyTech_Lab3)

find_package(Protobuf REQUIRED)

add_library(udp_socket src/udp_socket.cpp)

add_executable(server app/udp_server.cpp generated/message.pb.cc)

target_link_libraries(server PRIVATE udp_socket protobuf::libprotobuf)

add_executable(client app/udp_client.cpp generated/message.pb.cc)

target_link_libraries(client PRIVATE udp_socket protobuf::libprotobuf)

target_include_directories(server PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(client PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(udp_socket PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(server PRIVATE generated/)
target_include_directories(client PRIVATE generated/)
target_include_directories(udp_socket PRIVATE ${CMAKE_SOURCE_DIR}/generated)

install(TARGETS server client DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
