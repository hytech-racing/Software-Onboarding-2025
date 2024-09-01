cmake_minimum_required(VERSION 3.15...3.30)

project(HelloWorldLab1 VERSION 1.0
                  DESCRIPTION "lab 1 hello world"
                  LANGUAGES CXX)

add_library(HelloWorldLibrary STATIC src/hello_world.cpp include/hello_world.h)
add_executable(HelloWorld src/main.cpp)

target_link_libraries(HelloWorld PRIVATE HelloWorldLibrary)