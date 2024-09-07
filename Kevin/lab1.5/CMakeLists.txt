cmake_minimum_required(VERSION 3.30)
project(Lab1.2)

add_library(HelloWorldLib STATIC src/hellolib.cpp include/hellolib.hpp)
target_include_directories(HelloWorldLib PUBLIC include)

add_executable(Lab1.2 src/HelloWorld.cpp)
target_link_libraries(Lab1.2 PUBLIC HelloWorldLib)