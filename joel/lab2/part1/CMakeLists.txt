cmake_minimum_required(VERSION 3.15)

project(OnboardingLab1.2 VERSION 1.0
                  DESCRIPTION "Onboarding"
                  LANGUAGES CXX)

add_library(hello_world STATIC src/hello_world.cpp)
target_include_directories(hello_world PUBLIC include)

add_executable(target src/main.cpp)
target_link_libraries(target PUBLIC hello_world)

install(TARGETS target DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)