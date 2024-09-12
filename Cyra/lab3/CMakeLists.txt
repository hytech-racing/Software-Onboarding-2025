cmake_minimum_required(3.10.1)
project(clientserver)

find_package(Protobuf REQUIRED)

add_library(communication STATIC src/Comm.cpp)
target_include_directories(communication PUBLIC include)

add_library(message STATIC src/message.pb.cc)
target_include_directories(message PUBLIC include)

target_link_libraries(message PUBLIC protobuf::libprotobuf)
target_link_libraries(communication PUBLIC message)

add_executable(server src/server.cpp)
target_link_libraries(server PUBLIC communication)
target_link_libraries(server PUBLIC message)

add_executable(client src/client.cpp)
target_link_libraries(client PUBLIC communication)
target_link_libraries(client PUBLIC message)

install(TARGETS client server
  RUNTIME DESTINATION bin
)