cmake_minimum_required(VERSION 3.24)
project(hello_world LANGUAGES CXX)

add_library(hellolib STATIC src/hello.cpp)
target_include_directories(hellolib PUBLIC include)
target_compile_features(hellolib PUBLIC cxx_std_11)

add_executable(hello_world src/main.cpp)
target_link_libraries(hello_world PUBLIC hellolib)

install(TARGETS hello_world DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)