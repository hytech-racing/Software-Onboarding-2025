cmake_minimum_required(VERSION 3.24)

project(hello_world LANGUAGES CXX)

find_package(hellolib REQUIRED)

add_executable(hello src/main.cpp)
target_link_libraries(hello PUBLIC hellolib::hellolib)



install(TARGETS hello DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)

