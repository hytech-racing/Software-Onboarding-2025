cmake_minimum_required(VERSION 3.15...3.30)
project(helloapp VERSION 0.1.0 LANGUAGES CXX)


find_package(hellolib REQUIRED)


add_executable(helloapp main.cpp)

target_link_libraries(helloapp PUBLIC hellolib)

install(TARGETS helloapp
    RUNTIME DESTINATION bin
)