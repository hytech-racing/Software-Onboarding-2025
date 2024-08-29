cmake_minimum_required(VERSION 3.14)

project(hello_world LANGUAGES CXX)
add_library(one STATIC src/test.cpp include/random.h)
project(part_1)

add_executable(part_1 src/HelloWorld.cpp)