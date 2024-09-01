cmake_minimum_required(VERSION 3.14)
project(nixintro)
add_executable(nixtest src/main.cpp)

add_library(hellolib SHARED src/helloLib.cpp)
include_directories(include)
target_link_libraries(nixtest shared hellolib)