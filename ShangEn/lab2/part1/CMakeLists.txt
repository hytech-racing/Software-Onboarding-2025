cmake_minimum_required(VERSION 3.22)

project(hello_world LANGUAGES CXX)

add_library(hello_world_lib SHARED src/hellolib.cpp)
target_include_directories(hello_world_lib PUBLIC include)

add_executable(test src/main.cpp)
target_link_libraries(test PUBLIC hello_world_lib)

include(GNUInstallDirs)
install(TARGETS test DESTINATION ${CMAKE_INSTALL_BINDIR})
install(TARGETS hello_world_lib DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(
    DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_PREFIX}/include
    FILES_MATCHING PATTERN "*.h*"
)