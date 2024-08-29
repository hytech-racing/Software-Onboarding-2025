cmake_minimum_required(VERSION 3.15...3.30)
project(new_project
        VERSION 1.0
        DESCRIPTION "New project"
        LANGUAGES CXX)
add_executable(MyFile src/main.cpp)
add_library(MyLibrary src/main.cpp
        src/hello_world.h)