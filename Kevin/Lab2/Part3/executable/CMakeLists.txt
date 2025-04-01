cmake_minimum_required(VERSION 3.15...3.30)
project(HelloWorldExecutable VERSION 1.0
                             DESCRIPTION "Executable for Part 2 of lab 2"
                             LANGUAGES CXX)

add_executable(helloWorldProgram src/main.cpp)
find_package(HelloWorldLibrary REQUIRED)

target_link_libraries(helloWorldProgram PUBLIC HelloWorldLibrary::HelloWorldLibrary)

install(TARGETS helloWorldProgram DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)