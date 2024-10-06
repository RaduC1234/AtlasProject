# Server CMakeLists.txt

cmake_minimum_required(VERSION 3.10)  # Minimum required CMake version
project(Server)  # Set project name

# Add the server executable
file(GLOB_RECURSE SERVER_SOURCES "src/*.cpp" )

file(GLOB_RECURSE SERVER_HEADERS "src/*.hpp")

add_executable(server ${SERVER_SOURCES} ${SERVER_HEADERS})

# Specify the engine dependency
target_link_libraries(server PRIVATE engine)  # Link the engine static library

# Link spdlog to the client executable
target_link_libraries(server PRIVATE spdlog::spdlog)  # Link spdlog

# Include directories
target_include_directories(server PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)  # Adjust as necessary
