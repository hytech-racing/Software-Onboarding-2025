cmake_minimum_required(VERSION 3.24)
project(client-server LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)

# Find protobuf package
find_package(Protobuf REQUIRED)

# WHOLE SECTION EXEMPLIFIES BAD PRACTICE!
# set(PROTOBUF_PROTO_DIR ${CMAKE_SOURCE_DIR}/proto)
# # Define path variables DONT
# set(PROTO_SRCS
#     ${PROTOBUF_PROTO_DIR}/christine/christine.pb.cc
#     ${PROTOBUF_PROTO_DIR}/hytech/hytech.pb.cc
# )
# set(PROTO_HDRS
#     ${PROTOBUF_PROTO_DIR}/christine/christine.pb.h
#     ${PROTOBUF_PROTO_DIR}/hytech/hytech.pb.h
# )
# Include directories DONT
# include_directories(${PROTOBUF_INCLUDE_DIRS})
# include_directories(${PROTOBUF_PROTO_DIR})
# include_directories(include)


add_library(server_driver src/server_driver.cpp)
add_library(client_driver src/client_driver.cpp )

#Made two protobuf message just to play around (I can delete this if u want/if its better to just put them in the same proto file)
add_library(hytech  src/hytech.pb.cc)
add_library(christine src/christine.pb.cc )

target_include_directories(client_driver PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:include>"
)
target_include_directories(server_driver PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:include>"
)
target_include_directories(christine PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:include>"
)
target_include_directories(hytech PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:include>"
)

#Link the necessary targets 
target_link_libraries(christine Protobuf)
target_link_libraries(hytech Protobuf)
target_link_libraries(client_driver christine hytech)
target_link_libraries(server_driver christine hytech)

# Add the server executable DONT DO THIS use targets include
add_executable(server app/server_main.cpp)
target_link_libraries(server server_driver)

# Add the client executable
add_executable(client app/client_main.cpp )
target_link_libraries(client client_driver)

#install targets!!
install(TARGETS server client DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)