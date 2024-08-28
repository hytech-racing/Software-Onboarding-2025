cmake_minimum_required(VERSION 3.5)

project(hello_library)

# Create the library
add_library(hello_library STATIC 
    src/hello.cpp
)

# target_include_directories(hello_library 
#     PUBLIC 
#         ${CMAKE_CURRENT_SOURCE_DIR}/include
# )


target_include_directories(hello_library 
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
# target_link_libraries(hello_binary
#     PRIVATE 
#         hello_library
# )

include(GNUInstallDirs)

install(TARGETS hello_library

    EXPORT hello_targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}

    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}

    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}

    PUBLIC_HEADER DESTINATION include
)

install (FILES include/hello.hpp DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

include(CMakePackageConfigHelpers)
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/helloConfig.cmake.in
    "${CMAKE_CURRENT_BINARY_DIR}/helloConfig.cmake"
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/hello
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/helloConfig.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/hello
)

# install (TARGETS hello_binary DESTINATION ${CMAKE_INSTALL_BINDIR})
install(EXPORT hello_targets
    FILE helloTargets.cmake
    NAMESPACE hello::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/hello)