cmake_minimum_required(VERSION 3.24)
project(client LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)

find_package(Protobuf REQUIRED)


add_library(host src/Host.cpp)
add_library(data STATIC src/data.pb.cc)

target_include_directories(host PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:include>"
)
target_include_directories(data PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:include>"
)

target_link_libraries(data PUBLIC protobuf::libprotobuf)
target_link_libraries(host PUBLIC data)

add_executable(server app/serverMain.cpp)
target_link_libraries(server PUBLIC host)

add_executable(client app/clientMain.cpp )
target_link_libraries(client PUBLIC host)

install(TARGETS server client DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)