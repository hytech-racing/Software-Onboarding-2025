cmake_minimum_required(VERSION 3.0.0)
project(HyTech_Lab1_P2 VERSION 0.1.0 LANGUAGES C CXX)

add_library(hello_world_library STATIC src/hello_world.cpp)
target_include_directories(hello_world_library PUBLIC include/)

add_executable(HyTech_Lab1_P2 src/main.cpp)

target_link_libraries(HyTech_Lab1_P2 PUBLIC hello_world_library)