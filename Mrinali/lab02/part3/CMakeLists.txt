cmake_minimum_required(VERSION 3.24)
project(helloapp)

find_package(hellolib REQUIRED)

add_executable(helloapp main.cpp)

target_link_libraries(helloapp PUBLIC hellolib::hellolib)

install(TARGETS helloapp DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)