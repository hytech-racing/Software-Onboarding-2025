cmake_minimum_required(VERSION 3.15...3.30)

project(HelloWorldLab2 VERSION 1.0
                  DESCRIPTION "lab 2 hello world"
                  LANGUAGES CXX)

add_library(HelloWorldLibrary STATIC src/hello_world.cpp include/hello_world.h)

target_include_directories(HelloWorldLibrary PUBLIC include)

add_executable(HelloWorld src/main.cpp)

target_link_libraries(HelloWorld PRIVATE HelloWorldLibrary)

include(GNUInstallDirs)

install (TARGETS HelloWorld DESTINATION ${CMAKE_INSTALL_BINDIR})