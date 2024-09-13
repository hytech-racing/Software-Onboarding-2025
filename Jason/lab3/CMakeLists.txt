cmake_minimum_required(VERSION 3.10)
project(Lab3)

find_package(Protobuf REQUIRED)

# Define the library
add_library(msg STATIC src/proto/message.pb.cc)

#Link the necessary targets 
target_link_libraries(msg PUBLIC protobuf::libprotobuf)

# Add the server executable 
add_executable(server src/server.cpp)
target_link_libraries(server PUBLIC msg)
target_link_libraries(server PUBLIC src/UDPSocket.cpp)

# Add the client executable
add_executable(client src/client.cpp )
target_link_libraries(client PUBLIC msg)
target_link_libraries(client PUBLIC src/UDPSocket.cpp)

install (TARGETS server client DESTINATION ${CMAKE_INSTALL_BINDIR})