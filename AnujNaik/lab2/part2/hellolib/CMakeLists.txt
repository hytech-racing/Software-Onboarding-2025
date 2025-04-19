cmake_minimum_required(VERSION 3.1)
project(hellolib VERSION 1.0 DESCRIPTION "hellolib library")

# Define the libraries
add_library(hellolib STATIC src/hellolib.cpp)


# Specify include directories for the bar library 
target_include_directories(hellolib PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:include>"
)

# Include the GNUInstallDirs module to use CMake's standard installation directories
include(GNUInstallDirs)

# Install targets
install(TARGETS hellolib
    EXPORT hellolibTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES DESTINATION include
)

#install(FILES bar.hpp DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# Configure and install the package config file
include(CMakePackageConfigHelpers)

# Generate the package config file
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/hellolibConfig.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/hellolibConfig.cmake"
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/hellolib
)

# Install the package config file
install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/hellolibConfig.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/hellolib
)

# Export targets for use in other projects
install(EXPORT hellolibTargets
    FILE hellolibTargets.cmake
    NAMESPACE hellolib::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/hellolib
)

install(
    DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_PREFIX}/include
    FILES_MATCHING PATTERN "*.hpp"
)