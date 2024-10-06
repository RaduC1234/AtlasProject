cmake_minimum_required(VERSION 3.10)
project(AtlasProject)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add subdirectories for engine, client, and server
add_subdirectory(engine)
add_subdirectory(client)
add_subdirectory(server)
