cmake_minimum_required(VERSION 3.5.0)
project(Lab1 VERSION 0.1.0 LANGUAGES C CXX)

add_library(lib src/print.cpp include/print.h)
target_include_directories(lib PUBLIC include)

add_executable(Lab1 src/main.cpp)
target_link_libraries(Lab1 PRIVATE lib)

