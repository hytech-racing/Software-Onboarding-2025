# cmake_minimum_required(3.10.1)
project(clientserver)

find_package(Protobuf REQUIRED)

add_library(message STATIC include/message.pb.cc)
target_include_directories(message PUBLIC include)

target_link_libraries(message PUBLIC protobuf::libprotobuf)

add_executable(server src/server.cpp)
target_link_libraries(server PUBLIC message)
target_include_directories(server PUBLIC include)

add_executable(client src/client.cpp)
target_link_libraries(client PUBLIC message)

install(TARGETS client server
  RUNTIME DESTINATION bin
)