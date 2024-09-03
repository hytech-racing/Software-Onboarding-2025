cmake_minimum_required(VERSION 3.24)

project(hello_world_project LANGUAGES CXX)

add_library(hello_world_lib STATIC src/hello_world.cpp)
target_include_directories(hello_world_lib PUBLIC include)

add_executable(hello_world src/main.cpp)
target_link_libraries(hello_world PUBLIC hello_world_lib)

install(TARGETS hello_world
  RUNTIME DESTINATION bin
)