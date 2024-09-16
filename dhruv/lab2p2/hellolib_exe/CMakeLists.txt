cmake_minimum_required(VERSION 3.15...3.30)
project(lab2p2 LANGUAGES CXX)

find_package(hellolib REQUIRED)

add_executable(HelloWorld main.cpp)

target_link_directories(HelloWorld PUBLIC HelloLib::HelloLib)

install(TARGETS HelloWorld RUNTIME DESTINATION bin)



