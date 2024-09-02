cmake_minimum_required(VERSION 3.15)
project(hello_app)



find_package(hello_lib REQUIRED)

add_executable(hello_app main.cpp)


target_link_libraries(hello_app PRIVATE hello_lib::hello_lib)

set_target_properties(hello_app PROPERTIES CXX_STANDARD 17)
target_compile_features(hello_app PUBLIC cxx_std_17)

install(TARGETS hello_app DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)