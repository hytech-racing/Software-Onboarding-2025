# Modified from the following CMakeLists.txt template: https://cliutils.gitlab.io/modern-cmake/chapters/basics/example.html

# Almost all CMake files should start with this
# You should always specify a range with the newest
# and oldest tested versions of CMake. This will ensure
# you pick up the best policies.
cmake_minimum_required(VERSION 3.24)

# This is your project statement. You should always list languages;
# Listing the version is nice here since it sets lots of useful variables
project(
  hello_world
  VERSION 1.0
  LANGUAGES CXX)

# Adding something we can run - Output name matches target name
add_executable(test src/HelloWorld.cpp)