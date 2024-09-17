cmake_minimum_required(VERSION 3.15...3.30)
project(project
        VERSION 1.0
        DESCRIPTION "New project"
        LANGUAGES CXX)


# Creates a binary file and compiles library
# Not specifying type is deprecated.
add_library(HelloWorldLibrary STATIC src/hello_world.cpp)


target_include_directories(HelloWorldLibrary PUBLIC include)

add_executable(hello_exec src/main.cpp)
target_link_libraries(hello_exec PUBLIC HelloWorldLibrary)

include(GNUInstallDirs)
install(TARGETS hello_exec
        DESTINATION ${CMAKE_INSTALL_BINDIR}
)