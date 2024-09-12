cmake_minimum_required(VERSION 3.24)
project(hello_lib)

find_package(hello_library REQUIRED)
add_executable(hello_lib main.cpp)
target_link_libraries(hello_lib PUBLIC hello_library::hello_library)

install(TARGETS hello_lib
  RUNTIME DESTINATION bin
)


