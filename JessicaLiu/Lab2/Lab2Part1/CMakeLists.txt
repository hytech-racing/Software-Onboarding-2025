cmake_minimum_required(VERSION 3.15...3.30)

project(Lab2 VERSION 1.0
                          DESCRIPTION "HyTech Software Training Lab 2"
                          LANGUAGES CXX)


add_library(helloworld_lib STATIC src/hello.cpp)

target_include_directories(helloworld_lib PUBLIC include)

# creates a target executable file
# helloworld is the name of the executable file that will be generated
# src/main.cpp is the relative path to a source file
add_executable(helloworld src/main.cpp)
target_link_libraries(helloworld PUBLIC helloworld_lib)

include(GNUInstallDirs)

install (TARGETS helloworld DESTINATION ${CMAKE_INSTALL_BINDIR})