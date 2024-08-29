cmake_minimum_required(VERSION 3.1)
project(
    ccp_playground VERSION 1.0
                  DESCRIPTION "Playing around with cmake"
)

find_package(bar REQUIRED)

#declare executable
add_executable(target playing.cpp)

#link together
target_link_libraries(target PUBLIC bar::bar)


target_include_directories(target PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/bar"
                          )


set_target_properties(target PROPERTIES CXX_STANDARD 17)
target_compile_features(target PUBLIC cxx_std_17)

# Install the executable to bin directory
install(TARGETS target DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)

