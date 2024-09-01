cmake_minimum_required(VERSION 3.14)
project(nixintro)
include_directories(include)


add_library(hellolib SHARED src/hellolib.cpp)
add_executable(nixtest src/main.cpp)

