cmake_minimum_required(VERSION 3.0)
project(SoftwareOnboardingLab3)
find_package(Protobuf REQUIRED)

add_library(bufferLibrary STATIC src/protobuf.pb.cc)
target_include_directories(bufferLibrary PUBLIC include)
target_link_libraries(bufferLibrary PUBLIC protobuf::libprotobuf)


add_executable(client client.cpp)
add_executable(server server.cpp)


target_link_libraries(client PUBLIC bufferLibrary)
target_link_libraries(server PUBLIC bufferLibrary)

install(TARGETS client DESTINATION bin)
install(TARGETS server DESTINATION bin)