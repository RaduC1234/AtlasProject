cmake_minimum_required(VERSION 3.10)
project(SceneBuilder)

# Gather all source files for the scene_builder
file(GLOB_RECURSE SCENE_BUILDER_SOURCES "src/*.cpp" "src/*.hpp")

# Create the scene_builder as a shared library (DLL)
add_library(scene_builder SHARED ${SCENE_BUILDER_SOURCES})

# Include directories for scene_builder
target_include_directories(scene_builder PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Link the scene_builder to the engine (assuming 'engine' is another target defined in your project)
target_link_libraries(scene_builder PRIVATE engine)

target_include_directories(scene_builder PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Set properties for the output DLL (optional)
set_target_properties(scene_builder PROPERTIES
        OUTPUT_NAME "scene_builder"
)

# Define preprocessor macros for the library
target_compile_definitions(scene_builder PRIVATE "ATLAS_BUILD_SHARED")

# Copy the scene_builder DLL to the server's build directory after building the DLL
add_custom_command(TARGET scene_builder POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:scene_builder>        # The path to the scene_builder DLL
        $<TARGET_FILE_DIR:server>           # The directory where the Server executable is located
        COMMENT "Copying scene_builder DLL to the server build directory"
)
