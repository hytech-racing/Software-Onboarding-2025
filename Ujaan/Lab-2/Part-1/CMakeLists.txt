cmake_minimum_required(VERSION 3.5)

project(hello_library)

# Create the library
add_library(hello_library STATIC 
    src/hello.cpp
)

target_include_directories(hello_library 
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)

# Create the executable

add_executable(hello_binary
    src/main.cpp
)

target_link_libraries(hello_binary
    PRIVATE 
        hello_library
)

include(GNUInstallDirs)

install (TARGETS hello_binary DESTINATION ${CMAKE_INSTALL_BINDIR})