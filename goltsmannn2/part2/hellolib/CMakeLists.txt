cmake_minimum_required(VERSION 3.0)
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

project(HelloLib
        VERSION 1.0
        LANGUAGES CXX
)
#SHARED IS 1) NOT COPIED TO SOURCE 2) DOESN'T CARRY UPSTREAM DEPENDENCIES

add_library(HelloLibrary SHARED src/hellolib.cpp)
target_include_directories(HelloLibrary PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)

install(TARGETS HelloLibrary
        EXPORT HelloLibraryTargets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        PUBLIC_HEADER DESTINATION include
)

install(EXPORT HelloLibraryTargets
        FILE HelloLibraryTargets.cmake
        NAMESPACE HelloLibrary::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/HelloLibrary
)

configure_package_config_file(${CMAKE_CURRENT_LIST_DIR}/cmake/HelloLibraryConfig.cmake.in
        "${CMAKE_CURRENT_BINARY_DIR}/HelloLibraryConfig.cmake"
        INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/HelloLibrary
)

install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/HelloLibraryConfig.cmake"
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/HelloLibrary
)

install(
        DIRECTORY include/
        DESTINATION ${CMAKE_INSTALL_PREFIX}/include
        FILES_MATCHING PATTERN "*.h*"
)