cmake_minimum_required(VERSION 3.1)
project(bar VERSION 1.0 DESCRIPTION "bar library")

# Define the libraries
add_library(foo STATIC src/foo.cpp)
add_library(bar STATIC src/bar.cpp)

# Include the GNUInstallDirs module
include(GNUInstallDirs)

# Specify include directories () -- ensures correct include paths are being used
#during build, compiler will look for header files in include dir
#during install, compiler will look for header files in ...
target_include_directories(foo PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:include>"
)

target_include_directories(bar PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:include>"
)

# Link bar to foo
target_link_libraries(bar PUBLIC foo)

# Install targets
install(TARGETS foo bar
    #makes the package easily findable by other
    EXPORT barTargets 
    #shared libraries
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    #static libraries
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    #typically for executables
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    #header files in include
    PUBLIC_HEADER DESTINATION include
)

# Install header files - BAD PRACTICE!
# install(FILES include/bar.hpp include/foo.hpp DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# Configure and install the package config file (the barConfig.cmake.in we made)
include(CMakePackageConfigHelpers)
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/barConfig.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/barConfig.cmake"
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/bar
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/barConfig.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/bar
)

# export bar info to barTargets.cmake
# When another project imports these targets, they will be prefixed with bar::
install(EXPORT barTargets 
    FILE barTargets.cmake
    NAMESPACE bar::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/bar
)
