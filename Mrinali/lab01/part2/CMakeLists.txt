cmake_minimum_required(VERSION 3.5)

project(hello_world LANGUAGES CXX)

add_library(hello_world_lib SHARED src/hello_world.cpp)
target_include_directories(hello_world_lib PUBLIC include)

add_executable(test src/main.cpp)
target_link_libraries(test PUBLIC hello_world_lib)