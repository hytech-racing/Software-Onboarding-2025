cmake_minimum_required(VERSION 3.5)

project(hello_world LANGUAGES CXX)

add_library(hello_world_lib STATIC src/hello_world.cpp)
target_include_directories(hello_world_lib PUBLIC include)
target_compile_features(hello_world_lib PUBLIC cxx_std_11)

add_executable(test src/main.cpp)
target_link_libraries(test PUBLIC hello_world_lib)

install(TARGETS test DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
