cmake_minimum_required(VERSION 3.10)
project(Lab3)

find_package(Protobuf REQUIRED)

# Define the library
add_library(msg STATIC proto/message.pb.cc)

#Link the necessary targets 
target_link_libraries(msg PUBLIC protobuf::libprotobuf)

# Specify include directories for this library
target_include_directories(hello_lib PUBLIC include)


# Add the server executable 
add_executable(server src/server.cpp)

# Add the client executable
add_executable(client src/client.cpp )

install (TARGETS server client DESTINATION ${CMAKE_INSTALL_BINDIR})