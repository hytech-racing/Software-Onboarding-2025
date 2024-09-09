cmake_minimum_required(VERSION 3.24)
project (nix_stuff LANGUAGES CXX)

add_library(Lab2_lib SHARED src/HelloWorld.cpp)
target_include_directories(Lab2_lib PUBLIC include)
target_compile_features(Lab2_lib PUBLIC cxx_std_11)

add_executable(nixTest src/main.cpp)
target_link_libraries(nixTest PUBLIC Lab2_lib)