cmake_minimum_required(VERSION 3.10)
project(Lab3)


find_package(Protobuf REQUIRED)

# Define the libraries
add_library(msg STATIC src/proto/message.pb.cc)
add_library(server STATIC src/server.cpp)
add_library(client STATIC src/client.cpp)

#Link the necessary targets 
target_link_libraries(msg PUBLIC protobuf::libprotobuf)
target_link_libraries(client PUBLIC msg)
target_link_libraries(server PUBLIC msg)

# Add the server executable 
add_executable(server_exe app/server_driver.cpp)
target_link_libraries(server_exe PUBLIC server)


# Add the client executable
add_executable(client_exe app/client_driver.cpp)
target_link_libraries(client_exe PUBLIC client)

install (TARGETS server_exe client_exe DESTINATION ${CMAKE_INSTALL_BINDIR})