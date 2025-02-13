# Specify the required CMake version range
cmake_minimum_required(VERSION 3.15...3.31)

# Project statement with version and languages
project(
  serverLib
  VERSION 1.0
  LANGUAGES CXX
)

find_package(Protobuf REQUIRED)

# Add the library target
add_library(telemetryLib ${CMAKE_SOURCE_DIR}/telemetry.pb.cc ${CMAKE_SOURCE_DIR}/telemetry.pb.h)

target_link_libraries(telemetryLib PRIVATE ${Protobuf_LIBRARIES})

# Include GNUInstallDirs to handle standard installation paths
include(GNUInstallDirs)


# Install the library target
install(TARGETS telemetryLib
  EXPORT telemetryLibTargets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# Export the library target for find_package
install(EXPORT telemetryLibTargets
  FILE telemetryLibTargets.cmake
  NAMESPACE telemetryLib::  
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/telemetryLib
)

# Use CMakePackageConfigHelpers to generate config file
include(CMakePackageConfigHelpers)

write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/telemetryLibConfigVersion.cmake
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY SameMajorVersion
)

file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/telemetryLibConfig.cmake
  "

include(\"\${CMAKE_CURRENT_LIST_DIR}/telemetryLibTargets.cmake\")

# Automatically find dependencies if required
find_package(Protobuf REQUIRED)
"
)

# Install the config and version files
install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/telemetryLibConfig.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/telemetryLibConfigVersion.cmake
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/telemetryLib
)

# Install header files
install(
  DIRECTORY include/
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  FILES_MATCHING PATTERN "*.h*"
)
