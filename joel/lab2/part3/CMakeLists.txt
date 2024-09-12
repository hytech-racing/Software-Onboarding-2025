cmake_minimum_required(VERSION 3.15...3.30)
project(part3lab VERSION 0.1.0 LANGUAGES CXX)

# Find the hellolib library
find_package(hellolib REQUIRED)

# Create the executable
add_executable(lab3app src/main.cpp)

# Link hellolib to the executable
target_link_libraries(lab3app PRIVATE hellolib)

# Installation rules for the executable
install(TARGETS lab3app
    DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
)
