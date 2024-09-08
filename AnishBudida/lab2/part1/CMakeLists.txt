cmake_minimum_required(VERSION 3.5)
project(lab2_part1 LANGUAGES CXX)
add_library(part1lib STATIC src/hello_world.cpp)

target_include_directories(part1lib PUBLIC include)

add_executable(part1 src/main.cpp)

target_link_libraries(part1 PUBLIC part1lib)

install(TARGETS part1 DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
