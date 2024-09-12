cmake_minimum_required(VERSION 3.15...3.30)
project(helloapp VERSION 0.1.0 LANGUAGES CXX)

# Find the hellolib library
find_package(hellolib REQUIRED)

# Create the executable
add_executable(helloapp main.cpp)

# Link hellolib to the executable
target_link_libraries(helloapp PRIVATE hellolib)

# Installation rules for the executable
install(TARGETS helloapp
    RUNTIME DESTINATION bin
)
