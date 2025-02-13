# Specify the required CMake version range
cmake_minimum_required(VERSION 3.15...3.31)

# Project statement with version and languages
project(
  serverLib
  VERSION 1.0
  LANGUAGES CXX
)

find_package(telemetryLib REQUIRED)
find_package(Protobuf REQUIRED)


# Include directories for headers
include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add the library target
add_library(serverLib ${CMAKE_SOURCE_DIR}/src/serverLib.cpp ${CMAKE_SOURCE_DIR}/include/serverLib.h)

target_link_libraries(serverLib PRIVATE telemetryLib::telemetryLib)
target_link_libraries(serverLib PRIVATE ${Protobuf_LIBRARIES})



# Include GNUInstallDirs to handle standard installation paths
include(GNUInstallDirs)

# Install the library target
install(TARGETS serverLib
  EXPORT serverLibTargets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# Export the library target for find_package
install(EXPORT serverLibTargets
  FILE serverLibTargets.cmake
  NAMESPACE serverLib::  
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/serverLib
)

# Use CMakePackageConfigHelpers to generate config file
include(CMakePackageConfigHelpers)

write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/serverLibConfigVersion.cmake
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY SameMajorVersion
)

file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/serverLibConfig.cmake
  "

include(\"\${CMAKE_CURRENT_LIST_DIR}/serverLibTargets.cmake\")

# Automatically find dependencies if required
find_package(Protobuf REQUIRED)
"
)

# Install the config and version files
install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/serverLibConfig.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/serverLibConfigVersion.cmake
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/serverLib
)

# Install header files
install(
  DIRECTORY include/
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  FILES_MATCHING PATTERN "*.h*"
)