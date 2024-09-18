cmake_minimum_required(VERSION 3.15...3.30)
project(hellolib_exe VERSION 0.1.0 LANGUAGES CXX)

# Find the hellolib library
find_package(hellolib REQUIRED)

# Create the executable
add_executable(hellolib_exe main.cpp)

# Link hellolib to the executable
target_link_libraries(hellolib_exe PRIVATE hellolib)

# Installation rules for the executable
install(TARGETS hellolib_exe
    RUNTIME DESTINATION bin
)

