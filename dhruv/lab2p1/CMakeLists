cmake_minimum_required(VERSION 3.15...3.30)
project(lab2p1 LANGUAGES CXX)

add_library(HelloWorldLib STATIC src/hello_world.cpp)
target_include_directories(HelloWorldLib PUBLIC include)

add_executable(HelloWorld src/main.cpp)
target_link_libraries(HelloWorld PUBLIC HelloWorldLib)

install(TARGETS HelloWorld DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)