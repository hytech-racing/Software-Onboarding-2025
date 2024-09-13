

cmake_minimum_required(VERSION 3.24)
project(hello_world)


add_library(hellolib SHARED src/hello.cpp)


target_include_directories(hellolib PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

install(TARGETS hellolib DESTINATION lib)

include(GNUInstallDirs)
install(TARGETS hellolib
  EXPORT hellolibTargets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  PUBLIC_HEADER DESTINATION include
)


install(EXPORT hellolibTargets
  FILE hellolibTargets.cmake
  NAMESPACE hellolib::  
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/collection
)

include(CMakePackageConfigHelpers)
configure_package_config_file(${CMAKE_CURRENT_LIST_DIR}/hellolibConfig.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/hellolibConfig.cmake"
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/collection
)

install(FILES
  "${CMAKE_CURRENT_BINARY_DIR}/hellolibConfig.cmake"
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/collection
)

install(
    DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_PREFIX}/include
    FILES_MATCHING PATTERN "*.hpp*"
    )