cmake_minimum_required(VERSION 3.0)
project(SoftwareOnboardingLab3)

add_executable(client client.cpp)
add_executable(server server.cpp)

install(TARGETS client DESTINATION bin)
install(TARGETS server DESTINATION bin)