# Engine CMakeLists.txt

cmake_minimum_required(VERSION 3.10)  # Minimum required CMake version
project(Engine)  # Set project name

# Create the static library for the engine
file(GLOB_RECURSE ENGINE_SOURCES "src/*.cpp")
file(GLOB_RECURSE ENGINE_HEADERS "src/*.hpp")

# Add spdlog as a subdirectory (ensure spdlog is cloned into the dependencies folder)
add_subdirectory(dependencies/spdlog)

# Create the engine static library
add_library(engine STATIC ${ENGINE_SOURCES} ${ENGINE_HEADERS})

# Specify include directories for the engine library
target_include_directories(engine
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        dependencies/spdlog/include  # Include path for spdlog
)

# Link spdlog to the engine library
target_link_libraries(engine PRIVATE spdlog::spdlog)  # Link spdlog
