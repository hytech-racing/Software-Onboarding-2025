cmake_minimum_required(VERSION 3.24)
project(lab3lib LANGUAGES CXX)

add_library(lab3lib STATIC src/mainFile.cpp)

# be sure that you use the generator expressions
# ($<BUILD_INTERFACE: and $<INSTALL_INTERFACE:) for your include directory setups
target_include_directories(lab3lib PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

include(GNUInstallDirs)
install(TARGETS lab3lib
  EXPORT lab3libTargets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  PUBLIC_HEADER DESTINATION include
)

# NAMESPACE sets the namespace that your target will live within.
# you can have multiple targets under the same namespace
install(EXPORT lab3libTargets
  FILE lab3libTargets.cmake
  NAMESPACE lab3lib::  
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/lab3lib
)

# this looks for your .cmake.in file that you created in step 1.
# if you set the directory differently you may need to handle this differently
include(CMakePackageConfigHelpers)
configure_package_config_file(${CMAKE_CURRENT_LIST_DIR}/cmake/lab3lib.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/lab3libConfig.cmake"
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/lab3lib
)

install(FILES
  "${CMAKE_CURRENT_BINARY_DIR}/lab3libConfig.cmake"
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/lab3lib
)


# actually install your header files
install(
    DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_PREFIX}/include
    FILES_MATCHING PATTERN "*.h*"
)
