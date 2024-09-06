cmake_minimum_required(VERSION 3.15...3.30)

project(
  Lab1FollowAlong
  VERSION 1.0
  LANGUAGES CXX)

add_library(helloworld_lib STATIC src/hello_world.cpp)

target_include_directories(helloworld_lib PUBLIC include)

add_executable(HelloWorld src/main.cpp)

target_link_libraries(HelloWorld PUBLIC helloworld_lib)