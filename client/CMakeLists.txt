# Client CMakeLists.txt

cmake_minimum_required(VERSION 3.10)  # Minimum required CMake version
project(Client)  # Set project name

# Add the client executable
file(GLOB_RECURSE CLIENT_SOURCES "src/*.cpp")

file(GLOB_RECURSE CLIENT_HEADERS "src/*.hpp")

add_executable(client ${CLIENT_SOURCES} ${CLIENT_HEADERS})

# Specify the engine dependency
target_link_libraries(client PRIVATE engine)  # Link the engine static library

# Link spdlog to the client executable
target_link_libraries(client PRIVATE spdlog::spdlog)  # Link spdlog

# Include directories
target_include_directories(client PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)  # Adjust as necessary
