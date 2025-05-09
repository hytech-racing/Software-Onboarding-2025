cmake_minimum_required(VERSION 3.15...3.30)

project(Lab2Part3 VERSION 1.0
                  DESCRIPTION "HyTech Software Training Lab 2 Part 3"
                  LANGUAGES CXX)

find_package(helloworld_lib REQUIRED)

# creates a target executable file
# helloworld is the name of the executable file that will be generated
# main.cpp is the relative path to a source file
add_executable(helloworld main.cpp)
target_link_libraries(helloworld PRIVATE helloworld_lib::helloworld_lib)

install(TARGETS helloworld RUNTIME DESTINATION bin)