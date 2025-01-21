# Almost all CMake files should start with this
# You should always specify a range with the newest
# and oldest tested versions of CMake. This will ensure
# you pick up the best policies.
cmake_minimum_required(VERSION 3.15...3.31)

# This is your project statement. You should always list languages;
# Listing the version is nice here since it sets lots of useful variables
project(
  serverApp
  VERSION 1.0
  LANGUAGES CXX)

find_package(telemetryLib REQUIRED)
find_package(serverLib REQUIRED)
find_package(Protobuf REQUIRED)


add_executable(clientApp ${CMAKE_SOURCE_DIR}/src/client.cpp)
add_executable(serverApp ${CMAKE_SOURCE_DIR}/src/server.cpp)

target_link_libraries(serverApp PRIVATE serverLib::serverLib)
target_link_libraries(serverApp PRIVATE telemetryLib::telemetryLib)
target_link_libraries(serverApp PRIVATE ${Protobuf_LIBRARIES})

target_link_libraries(clientApp PRIVATE serverLib::serverLib)
target_link_libraries(clientApp PRIVATE telemetryLib::telemetryLib)
target_link_libraries(clientApp PRIVATE ${Protobuf_LIBRARIES})


install(TARGETS clientApp
        RUNTIME DESTINATION bin)
			
install(TARGETS serverApp
		RUNTIME DESTINATION bin)