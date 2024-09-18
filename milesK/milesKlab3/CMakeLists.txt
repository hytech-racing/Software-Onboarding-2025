cmake_minimum_required(VERSION 3.10)
project(lab3)

find_package(Protobuf REQUIRED)

add_library(socket ${PROJECT_SOURCE_DIR}/socket.cpp)

add_executable(server ${PROJECT_SOURCE_DIR}/server.cpp proto/info.pb.cc)

target_link_libraries(server PRIVATE socket protobuf::libprotobuf)

add_executable(client ${PROJECT_SOURCE_DIR}/client.cpp proto/info.pb.cc)

target_link_libraries(client PRIVATE socket protobuf::libprotobuf)

target_include_directories(server PRIVATE proto/)
target_include_directories(client PRIVATE proto/)

install(TARGETS server client DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
