cmake_minimum_required(VERSION 3.24)
project(lab1_hard LANGUAGES CXX)
add_library(part2lib SHARED src/hello_world.cpp)
target_include_directories(part2lib PUBLIC include)
target_compile_features(part2lib PUBLIC cxx_std_11)


add_executable(hello_World src/main.cpp)
target_link_libraries(hello_World PUBLIC part2lib)