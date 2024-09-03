cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(OnboardingLab1.2 VERSION 1.0
                  DESCRIPTION "Onboarding"
                  LANGUAGES CXX)

add_library(hello_world SHARED src/hello_world.cpp)
target_include_directories(hello_world PUBLIC include)

add_executable(a src/main.cpp)
target_link_libraries(a PUBLIC hello_world)
