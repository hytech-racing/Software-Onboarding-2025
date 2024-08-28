
cmake_minimum_required(VERSION 3.15...3.30)

project(Lab1Part2)

add_library(L1P2 STATIC hello_world.cpp)

target_include_directories(L1P2 PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(Lab1 main.cpp)

target_link_libraries(Lab1 PRIVATE L1P2)

include(GNUInstallDirs)

install (TARGETS Lab1 DESTINATION ${CMAKE_INSTALL_BINDIR})