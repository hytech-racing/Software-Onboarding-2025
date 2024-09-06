cmake_minimum_required(VERSION 3.24)
project(client-server LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)

find_package(Protobuf REQUIRED)


add_library(hub src/Hub.cpp)
add_library(data STATIC src/data.pb.cc)

target_include_directories(hub PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:include>"
)
target_include_directories(data PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:include>"
)

#Link the necessary targets 
target_link_libraries(data PUBLIC protobuf::libprotobuf)
target_link_libraries(hub PUBLIC data)

# Add the server executable DONT DO THIS use targets include
add_executable(server app/serverMain.cpp)
target_link_libraries(server PUBLIC hub)

# Add the client executable
add_executable(client app/clientMain.cpp )
target_link_libraries(client PUBLIC hub)

#install targets!!
install(TARGETS server client DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)