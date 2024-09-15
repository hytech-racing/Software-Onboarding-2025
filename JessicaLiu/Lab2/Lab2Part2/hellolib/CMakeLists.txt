cmake_minimum_required(VERSION 3.15...3.30)

project(Lab2 VERSION 1.0
                          DESCRIPTION "HyTech Software Training Lab 2"
                          LANGUAGES CXX)

add_library(helloworld_lib SHARED src/hello.cpp)

target_include_directories(helloworld_lib PUBLIC 
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

include(GNUInstallDirs)

install(TARGETS helloworld_lib
  EXPORT helloworld_libTargets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  PUBLIC_HEADER DESTINATION include
)

# NAMESPACE sets the namespace that your target will live within.
# you can have multiple targets under the same namespace
install(EXPORT helloworld_libTargets
  FILE helloworld_libTargets.cmake
  NAMESPACE helloworld_lib::  
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/helloworld_lib
)

# this looks for your .cmake.in file that you created in step 1.
# if you set the directory differently you may need to handle this differently
include(CMakePackageConfigHelpers)
configure_package_config_file(${CMAKE_CURRENT_LIST_DIR}/cmake/helloworld_libConfig.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/helloworld_libConfig.cmake"
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/helloworld_lib
)

install(FILES
  "${CMAKE_CURRENT_BINARY_DIR}/helloworld_libConfig.cmake"
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/helloworld_lib
)

# actually install your header files
install(
    DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_PREFIX}/include
    FILES_MATCHING PATTERN "*.h*"
    )