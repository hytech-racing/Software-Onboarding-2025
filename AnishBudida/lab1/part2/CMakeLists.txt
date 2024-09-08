cmake_minimum_required(VERSION 3.5)
project(lab1_part2 LANGUAGES CXX)
add_library(part2lib SHARED src/main.cpp)

target_include_directories(part2lib PUBLIC include)

add_executable(part2 src/main.cpp)

target_link_libraries(part2 PUBLIC part2lib)
