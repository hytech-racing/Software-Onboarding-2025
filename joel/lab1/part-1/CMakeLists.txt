cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(Onboarding VERSION 1.0
                  DESCRIPTION "Onboarding"
                  LANGUAGES CXX)


add_executable(a src/main.cpp)