cmake_minimum_required(VERSION 3.15...3.30)

project(
  lab1Example
  VERSION 1.0
  LANGUAGES CXX)

add_library(HelloWorldlib STATIC src/hello_world.cpp include/hello_world.h)

target_include_directories(HelloWorldlib PUBLIC include)

# target_compile_features(HelloWorldlib PUBLIC cxx_std_11)

add_executable(main src/main.cpp)

target_link_libraries(main PUBLIC HelloWorldlib)