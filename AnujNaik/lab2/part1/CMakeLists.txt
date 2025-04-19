cmake_minimum_required(VERSION 3.1)
project(
    ccp_playground VERSION 1.0
                  DESCRIPTION "Playing around with cmake"
)

add_library(hellolib STATIC src/hellolib.cpp)

target_include_directories(hellolib PUBLIC include)
add_executable(target src/main.cpp)

target_link_libraries(target PUBLIC hellolib)

set_target_properties(target PROPERTIES CXX_STANDARD 17)
target_compile_features(target PRIVATE cxx_std_17)

# Install the executable to bin directory
install(TARGETS target DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)