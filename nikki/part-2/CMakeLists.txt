cmake_minimum_required(VERSION 3.15)
project(HelloWorld LANGUAGES CXX)

add_library(hello_lib STATIC hello_world.cpp)
target_include_directories(hello_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(hello_exec main.cpp)

target_link_libraries(hello_exec PRIVATE hello_lib)

include(GNUInstallDirs)

install (TARGETS hello_exec DESTINATION ${CMAKE_INSTALL_BINDIR})