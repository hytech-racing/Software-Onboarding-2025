cmake_minimum_required(VERSION 3.5)

project(hello_exe)

# set(CMAKE_PREFIX_PATH ${CMAKE_CURRENT_LIST_DIR})

find_package(hello REQUIRED)


add_executable(
    target 
        src/main.cpp
    )

target_link_libraries(target PUBLIC hello::hello_library)

target_include_directories(target PUBLIC
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}/include"
)

install(TARGETS target DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)