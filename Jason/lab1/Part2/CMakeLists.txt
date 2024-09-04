cmake_minimum_required(VERSION 3.10)
project(Lab1_Hard)

# Define the library
add_library(hello_world STATIC src/hello_world.cpp)

# Specify include directories for this library
target_include_directories(hello_world PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includes)

# Define the executable
add_executable(Lab1_Hard src/main.cpp)

# Link the hello_world library to the executable
target_link_libraries(Lab1_Hard PRIVATE hello_world)

