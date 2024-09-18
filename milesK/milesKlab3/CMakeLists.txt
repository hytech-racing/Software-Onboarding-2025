cmake_minimum_required(VERSION 3.10)
project(lab3)

include(GNUInstallDirs)
find_package(Protobuf REQUIRED)

add_library(socket STATIC src/socket.cpp)

add_executable(server src/server.cpp src/info.pb.cc)
add_executable(client src/client.cpp src/info.pb.cc)

target_link_libraries(server PRIVATE socket protobuf::libprotobuf)
target_link_libraries(client PRIVATE socket protobuf::libprotobuf)

target_include_directories(server PUBLIC include/)
target_include_directories(client PUBLIC include/)

install(TARGETS server client RUNTIME DESTINATION bin)
