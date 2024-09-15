cmake_minimum_required(VERSION 3.15...3.30)

project(HelloWorldLab2Pt2 LANGUAGES CXX)

find_package(hellolib REQUIRED)

add_executable(HelloWorld main.cpp)

target_link_libraries(HelloWorld PRIVATE hellolib::hellolib)

install(TARGETS HelloWorld RUNTIME DESTINATION bin)
