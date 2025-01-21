# Specify the required CMake version range
cmake_minimum_required(VERSION 3.15...3.31)

# Project statement with version and languages
project(
  HelloWorld
  VERSION 1.0
  LANGUAGES CXX
)

# Include directories for headers
include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add the library target
add_library(hello_world ${CMAKE_SOURCE_DIR}/src/HelloWorld.cpp ${CMAKE_SOURCE_DIR}/include/HelloWorld.h)

# Include GNUInstallDirs to handle standard installation paths
include(GNUInstallDirs)

# Install the library target
install(TARGETS hello_world
  EXPORT hello_worldTargets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# Export the library target for find_package
install(EXPORT hello_worldTargets
  FILE hello_worldTargets.cmake
  NAMESPACE hello_world::  
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/hello_world
)

# Use CMakePackageConfigHelpers to generate config file
include(CMakePackageConfigHelpers)
configure_package_config_file(${CMAKE_CURRENT_LIST_DIR}/cmake/hello_worldConfig.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/hello_worldConfig.cmake"
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/hello_world
)

# Install the generated config file
install(FILES
  "${CMAKE_CURRENT_BINARY_DIR}/hello_worldConfig.cmake"
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/hello_world
)

# Install header files
install(
  DIRECTORY include/
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  FILES_MATCHING PATTERN "*.h*"
)
