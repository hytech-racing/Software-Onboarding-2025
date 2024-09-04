cmake_minimum_required(VERSION 3.15...3.30)
project(lab2 VERSION 1.0 LANGUAGES CXX)
add_library(hellolib SHARED src/main.cpp)
target_include_directories(hellolib PUBLIC include)
add_executable(main src/main.cpp)
target_link_libraries(main PUBLIC hellolib)

install(TARGETS hellolib main
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)

install(FILES include/hellolib.hpp DESTINATION include)
