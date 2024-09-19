cmake_minimum_required(VERSION 3.14)
project(lab1_part2)
add_executable(test src/HelloWorld.cpp)

add_library(libtest SHARED src/libtest.cpp)
target_include_directories(libtest PUBLIC include)