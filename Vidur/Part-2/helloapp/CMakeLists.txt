cmake_minimum_required(VERSION 3.24)
project(hello_app LANGUAGES CXX)

find_package(hellolib REQUIRED)

add_executable(hello_app main.cpp)

target_link_libraries(hello_app PUBLIC hellolib::hellolib)

install(TARGETS hello_app DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)