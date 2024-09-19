cmake_minimum_required(VERSION 3.24)
project(lab3_app LANGUAGES CXX)

find_package(Protobuf REQUIRED)

add_library(mainFile src/mainFile.cpp)
add_library(info src/info.pb.cc)

target_include_directories(mainFile PUBLIC include)

target_include_directories(info PUBLIC include)

target_link_libraries(mainFile PUBLIC protobuf::libprotobuf)
target_link_libraries(info PUBLIC mainFile)

add_executable(lab3_client app/client.cpp)
target_link_libraries(lab3_client PUBLIC mainFile)

add_executable(lab3_server app/server.cpp)
target_link_libraries(lab3_server PUBLIC mainFile)

install(TARGETS lab3_client lab3_server DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
