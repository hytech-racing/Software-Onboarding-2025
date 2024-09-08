cmake_minimum_required(VERSION 3.15...3.30)

project(
  HW1_PART2
  VERSION 1.0
  LANGUAGES CXX)

add_library(HelloWorldLib src/hello_world.cpp)
target_include_directories(HelloWorldLib PUBLIC include)

add_executable(HelloWorld src/main.cpp)

target_link_libraries(HelloWorld PRIVATE HelloWorldLib)
