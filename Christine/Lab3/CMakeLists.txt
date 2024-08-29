cmake_minimum_required(VERSION 3.24)
project(client-server LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)

# Find protobuf package
find_package(Protobuf REQUIRED)

# Define the path to your protobuf .proto files
set(PROTOBUF_PROTO_DIR ${CMAKE_SOURCE_DIR}/proto)

# Define path variables
set(PROTO_SRCS
    ${PROTOBUF_PROTO_DIR}/christine/christine.pb.cc
    ${PROTOBUF_PROTO_DIR}/hytech/hytech.pb.cc
)

set(PROTO_HDRS
    ${PROTOBUF_PROTO_DIR}/christine/christine.pb.h
    ${PROTOBUF_PROTO_DIR}/hytech/hytech.pb.h
)

# Include directories
include_directories(${PROTOBUF_INCLUDE_DIRS})
include_directories(${PROTOBUF_PROTO_DIR})
include_directories(include)

# Add the server library
add_library(server_driver src/server_driver.cpp ${PROTO_SRCS} ${PROTO_HDRS})

# Add the client library
add_library(client_driver src/client_driver.cpp ${PROTO_SRCS} ${PROTO_HDRS})

# Add the server executable
add_executable(server app/server_main.cpp ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(server server_driver ${Protobuf_LIBRARIES})

# Add the client executable
add_executable(client app/client_main.cpp ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(client client_driver ${Protobuf_LIBRARIES})

#install targets!!
install(TARGETS server client DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)