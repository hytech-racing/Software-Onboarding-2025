cmake_minimum_required(VERSION 3.15...3.30)
project(lab2 VERSION 1.0 LANGUAGES CXX)

#find_package(hellolib REQUIRED)

add_library(hellolib SHARED src/main.cpp)
target_include_directories(hellolib PUBLIC include)
add_executable(main src/main.cpp)
target_link_libraries(main PUBLIC hellolib)

install(TARGETS hellolib main
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)

install(FILES include/hellolib.hpp DESTINATION include)

## ... all the above, except for the install directive
#
#include(GNUInstallDirs)
#install(TARGETS my_library
#EXPORT my_libraryTargets
#LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
#RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
#PUBLIC_HEADER DESTINATION include
#)
#
## NAMESPACE sets the namespace that your target will live within.
## you can have multiple targets under the same namespace
#install(EXPORT my_libraryTargets
#FILE my_libraryTargets.cmake
#NAMESPACE my_library::  
#DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/my_library
#)
#
## this looks for your .cmake.in file that you created in step 1.
## if you set the directory differently you may need to handle this differently
#include(CMakePackageConfigHelpers)
#configure_package_config_file(${CMAKE_CURRENT_LIST_DIR}/cmake/my_libraryConfig.cmake.in
#"${CMAKE_CURRENT_BINARY_DIR}/my_libraryConfig.cmake"
#INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/my_library
#)
#
#install(FILES
#"${CMAKE_CURRENT_BINARY_DIR}/my_libraryConfig.cmake"
#DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/my_library
#)
#
## actually install your header files
#install(
#DIRECTORY include/
#DESTINATION ${CMAKE_INSTALL_PREFIX}/include
#FILES_MATCHING PATTERN "*.h*"
#)
