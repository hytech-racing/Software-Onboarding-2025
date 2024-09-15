cmake_minimum_required(VERSION 3.24)
project(lab3_app LANGUAGES CXX)

find_package(lab3lib REQUIRED)

add_executable(lab3_client client.cpp)

add_executable(lab3_server server.cpp)

target_link_libraries(lab3_client PUBLIC lab3lib::lab3lib)

target_link_libraries(lab3_server PUBLIC lab3lib::lab3lib)

install(TARGETS lab3_client DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)

install(TARGETS lab3_server DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
