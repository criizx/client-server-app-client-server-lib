cmake_minimum_required(VERSION 3.10)
project(display_server LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(DISPLAY_SERVER_SOURCES
    src/main.cpp

    src/handler.cpp
)

add_executable(display_server ${DISPLAY_SERVER_SOURCES})

target_include_directories(display_server PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(display_server PRIVATE server_lib)
