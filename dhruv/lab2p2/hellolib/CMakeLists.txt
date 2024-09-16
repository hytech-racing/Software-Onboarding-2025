cmake_minimum_required(VERSION 3.15...3.30)

project(HelloLib LANGUAGES CXX)

add_library(HelloLib SHARED src/hellolib.cpp)
target_include_directories(HelloLib PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

include(GNUInstallDirs)
install(TARGETS HelloLib
  EXPORT HelloLibTargets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  PUBLIC_HEADER DESTINATION include
)

# NAMESPACE sets the namespace that your target will live within.
# you can have multiple targets under the same namespace
install(EXPORT HelloLibTargets
  FILE HelloLibTargets.cmake
  NAMESPACE HelloLib::  
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/HelloLib
)

# this looks for your .cmake.in file that you created in step 1.
# if you set the directory differently you may need to handle this differently
include(CMakePackageConfigHelpers)
configure_package_config_file(${CMAKE_CURRENT_LIST_DIR}/cmake/HelloLibConfig.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/HelloLibConfig.cmake"
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/HelloLib
)

install(FILES
  "${CMAKE_CURRENT_BINARY_DIR}/HelloLibConfig.cmake"
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/HelloLib
)

install(
    DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    FILES_MATCHING PATTERN "*.hpp"
)