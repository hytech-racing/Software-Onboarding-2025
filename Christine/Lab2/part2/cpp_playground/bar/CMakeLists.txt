cmake_minimum_required(VERSION 3.1)
project(bar VERSION 1.0 DESCRIPTION "bar library")

# Define the libraries
add_library(foo STATIC foo.cpp foo.hpp)
add_library(bar STATIC bar.cpp bar.hpp)

# Link bar to foo
target_link_libraries(bar PRIVATE foo)

# Specify include directories for the bar library 
target_include_directories(bar PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

# Include the GNUInstallDirs module to use CMake's standard installation directories
include(GNUInstallDirs)

# Install targets
install(TARGETS foo bar
    EXPORT barTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# Install header files
install(FILES bar.hpp DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# Configure and install the package config file
include(CMakePackageConfigHelpers)

# Generate the package config file
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/barConfig.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/barConfig.cmake"
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/bar
)

# Install the package config file
install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/barConfig.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/bar
)

# Export targets for use in other projects
install(EXPORT barTargets
    FILE barTargets.cmake
    NAMESPACE bar::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/bar
)
