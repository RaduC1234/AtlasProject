cmake_minimum_required(VERSION 3.28)
project(Client)

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)



# Add the server executable
file(GLOB_RECURSE SERVER_SOURCES "src/*.cpp" "src/*.hpp")

add_executable(client ${SERVER_SOURCES})
target_link_libraries(client PRIVATE engine)

target_include_directories(client PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_compile_features(client PRIVATE cxx_std_20)

if(WIN32)
    add_custom_command(
            TARGET client
            COMMENT "Copy OpenAL DLL"
            PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:client>
            VERBATIM)
endif()
