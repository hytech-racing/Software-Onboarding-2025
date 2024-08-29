cmake_minimum_required(VERSION 3.1)
project(
    ccp_playground VERSION 1.0
                  DESCRIPTION "Playing around with cmake"
)

add_library(foo STATIC src/foo.cpp)
add_library(bar STATIC src/bar.cpp)

add_executable(target app/playing.cpp)

target_include_directories(bar
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)
target_include_directories(foo
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(bar PRIVATE foo)

target_link_libraries(target PRIVATE bar)

set_target_properties(target PROPERTIES CXX_STANDARD 17)
target_compile_features(target PRIVATE cxx_std_17)

# Install the executable to bin directory
install(TARGETS target DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)