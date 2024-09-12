cmake_minimum_required(VERSION 3.24)
project(hello_lib_exe)

find_package(hellolib REQUIRED)

add_executable(hello_world main.cpp)

target_link_libraries(hello_world PUBLIC hellolib::hellolib)

install(TARGETS hello_world RUNTIME DESTINATION bin)