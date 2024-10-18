cmake_minimum_required(VERSION 3.10)
project(Engine)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(SFML)

file(GLOB_RECURSE ENGINE_SOURCES "src/*.cpp" "src/*.hpp")

add_subdirectory(dependencies/glm)

add_library(engine OBJECT ${ENGINE_SOURCES})

target_include_directories(engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_libraries(engine
        PUBLIC
        glm
        sfml-graphics
)

target_compile_definitions(engine PUBLIC ATLAS_ENABLE_ASSERT)
