cmake_minimum_required(VERSION 3.1)
project(
    helloapp VERSION 1.0
                  DESCRIPTION "Playing around with cmake"
)

find_package(hellolib REQUIRED)

#declare executable
add_executable(helloapp main.cpp)

#link together
#Dont include binaries + useless! SUPER BAD!
#target_include_directories(target PUBLIC
#                          "${PROJECT_BINARY_DIR}"
#                          "${PROJECT_SOURCE_DIR}/bar"
#                          )


target_link_libraries(helloapp PRIVATE hellolib)

# Install the executable to bin directory
install(TARGETS helloapp RUNTIME DESTINATION bin)




# include(GNUInstallDirs)
# install(TARGETS hellolib
#   EXPORT hellolibTargets
#   LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#   ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
#   RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
#   PUBLIC_HEADER DESTINATION include
# )

# # NAMESPACE sets the namespace that your target will live within.
# # you can have multiple targets under the same namespace
# install(EXPORT hellolibTargets
#   FILE hellolibTargets.cmake
#   NAMESPACE hellolib::  
#   DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/hellolib
# )

# # this looks for your .cmake.in file that you created in step 1.
# # if you set the directory differently you may need to handle this differently
# include(CMakePackageConfigHelpers)
# configure_package_config_file(${CMAKE_CURRENT_LIST_DIR}/cmake/hellolibConfig.cmake.in
#   "${CMAKE_CURRENT_BINARY_DIR}/hellolibConfig.cmake"
#   INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/hellolib
# )

# install(FILES
#   "${CMAKE_CURRENT_BINARY_DIR}/hellolibConfig.cmake"
#   DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/hellolib
# )

# # actually install your header files
# install(
#     DIRECTORY include/
#     DESTINATION ${CMAKE_INSTALL_PREFIX}/include
#     FILES_MATCHING PATTERN "*.h*"
#     )

