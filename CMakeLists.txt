cmake_minimum_required(VERSION 3.10)
project(Atlas)

# Set the C++ standard (optional)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the Engine
add_subdirectory(engine)

# Add the Client
add_subdirectory(client)

# Add the Server
add_subdirectory(server)

# Add the LevelBuilder
add_subdirectory(level_builder)
