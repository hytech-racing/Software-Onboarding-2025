cmake_minimum_required(VERSION 3.15...3.30)

project(HelloLibrary    VERSION 1.0
                        DESCRIPTION "Library for Part 2 of lab 2"
                        LANGUAGES CXX)

add_library(HelloWorldLibrary STATIC src/helloLibrary.cpp include/helloLibrary.h)

# Helper module for normal install prefixes
include(GNUInstallDirs)

target_include_directories(HelloWorldLibrary PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>  # The include directory before the library is built
    $<INSTALL_INTERFACE:include>                            # The include directory after the library is built
)

install(TARGETS HelloWorldLibrary
        EXPORT HelloWorldLibraryTargets         # Creates an "export set" that can be referenced later
        LIBRARY DESTINATION lib                 # Shared Libraries
        ARCHIVE DESTINATION lib                 # Static Libraries
        RUNTIME DESTINATION bin)                # Runtime Libraries

install(FILES include/helloLibrary.h DESTINATION include) # Install the header files

# Export the targets for find_package()
install(EXPORT HelloWorldLibraryTargets
        FILE HelloWorldLibraryTargets.cmake             # Puts the EXPORT set into a file
        NAMESPACE HelloWorldLibrary::
        DESTINATION lib/cmake/HelloWorldLibrary)

# Helper module to generate a config file
include(CMakePackageConfigHelpers)

# Generate the Config file
configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/HelloWorldLibraryConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/HelloWorldLibraryConfig.cmake
    INSTALL_DESTINATION lib/cmake/HelloWorldLibrary
)

# Install the Config and Version files
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/HelloWorldLibraryConfig.cmake
    DESTINATION lib/cmake/HelloWorldLibrary
)
