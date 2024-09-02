cmake_minimum_required(VERSION 3.15...3.30)
project(project
        VERSION 1.0
        DESCRIPTION "New project"
        LANGUAGES CXX)

add_library(HelloWorldLibrary SHARED src/hello_world.cpp)
target_include_directories(HelloWorldLibrary PUBLIC include)

add_executable(main_file src/main.cpp)
target_link_libraries(main_file PUBLIC HelloWorldLibrary)