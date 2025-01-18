cmake_minimum_required(VERSION 3.15...3.30)
project(Lab2Pt1 VERSION 1.0
                DESCRIPTION "Part 2 of lab 1"
                LANGUAGES CXX)

add_executable(HelloWorldProgram src/main.cpp) # HelloWorldProgram is a "target name"

# We are making a target that contains the library
add_library(HelloWorldLibrary STATIC src/helloLibrary.cpp include/helloLibrary.h)
target_include_directories(HelloWorldLibrary PUBLIC include)

# We link the dependencies together
target_link_libraries(HelloWorldProgram HelloWorldLibrary)

# Provide installation path
install(TARGETS HelloWorldProgram DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)