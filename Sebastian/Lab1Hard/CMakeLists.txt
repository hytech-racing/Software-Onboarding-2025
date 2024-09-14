cmake_minimum_required(VERSION 3.24)
project(hello_world LANGUAGES CXX)

add_library(Lab1_lib SHARED src/HelloWorld.cpp)
target_include_directories(Lab1_lib PUBLIC include)
target_compile_features(Lab1_lib PUBLIC cxx_std_11)

add_executable(newTest src/main.cpp)
target_link_libraries(newTest PUBLIC Lab1_lib)