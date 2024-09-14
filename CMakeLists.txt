cmake_minimum_required(VERSION 3.0)
include(GNUInstallDirs)
project(HelloApp
        VERSION 1.0
        LANGUAGES CXX
)

find_package(HelloLibrary REQUIRED)
add_executable(HelloExec main.cpp)
target_link_libraries(HelloExec PRIVATE HelloLibrary::HelloLibrary)

install(TARGETS HelloExec DESTINATION bin)