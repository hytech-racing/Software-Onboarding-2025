cmake_minimum_required(VERSION 3.30)
project(Lab1_5)

add_library(HelloWorldLib STATIC src/hellolib.cpp include/hellolib.h)

target_include_directories(HelloWorldLib PUBLIC include)

add_executable(main src/HelloWorld.cpp)
target_link_libraries(main PUBLIC HelloWorldLib)