cmake_minimum_required(VERSION 3.22)

project(hello_world LANGUAGES CXX)

add_library(hello_world_lib SHARED src/part2.cpp)
target_include_directories(hello_world_lib PUBLIC include)

add_executable(test src/main.cpp)
target_link_libraries(test PUBLIC hello_world_lib)