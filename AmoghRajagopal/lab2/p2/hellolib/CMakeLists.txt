cmake_minimum_required(VERSION 3.0.0)
project(hello_lib VERSION 0.1.0 LANGUAGES C CXX)

add_library(hello_world_library STATIC src/hello_world.cpp)

target_include_directories(hello_world_library PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

include(GNUInstallDirs)

install(TARGETS hello_world_library
    EXPORT hello_world_library_targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    PUBLIC_HEADER DESTINATION include
)

install(EXPORT hello_world_library_targets
    FILE hello_world_library_targets.cmake
    NAMESPACE hello_world_library::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/hello_world_library
)

include(CMakePackageConfigHelpers)

configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/hello_world_libraryConfig.cmake.in
    "${CMAKE_CURRENT_BINARY_DIR}/hello_world_libraryConfig.cmake"
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/hello_world_library
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/hello_world_libraryConfig.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/hello_world_library
)

install(
    DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    FILES_MATCHING PATTERN "*.h*"
)
