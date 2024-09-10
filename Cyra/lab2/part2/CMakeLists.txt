cmake_minimum_required(VERSION 3.32)
project(hello_lib)

add_library(hello_lib STATIC src/hello.cpp)



target_include_directories(hello_lib PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

include(GNUInstallDirs)

install(TARGETS hello_lib
    EXPORT hello_libTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    INCLUDES DESTINATION INCLUDE
)


install(EXPORT hello_libTargets
  FILE hello_libTargets.cmake
  NAMESPACE hello_lib::  
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/hello_lib
)

include(CMakePackageConfigHelpers)

configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/hello_libConfig.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/hello_libConfig.cmake"
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/hello_lib
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/hello_libConfig.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/hello_lib
)


install(
    DIRECTORY src/
    DESTINATION ${CMAKE_INSTALL_PREFIX}/src
    FILES_MATCHING PATTERN "*.h*"
    )


