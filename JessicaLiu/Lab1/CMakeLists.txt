cmake_minimum_required(VERSION 3.15...3.30)

project(Lab1Part1 VERSION 1.0
                          DESCRIPTION "HyTech Software Training Lab 1"
                          LANGUAGES CXX)


add_library(helloworld_lib STATIC src/hello.cpp)

target_include_directories(helloworld_lib PUBLIC include)

# set_target_properties(helloworld_lib PROPERTIES LINKER_LANGUAGE CXX)

# creates a target executable file
# helloworld is the name of the executable file that will be generated
# src/main.cpp is the relative path to a source file
add_executable(helloworld src/main.cpp)
target_link_libraries(helloworld PUBLIC helloworld_lib)