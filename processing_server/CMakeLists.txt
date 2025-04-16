cmake_minimum_required(VERSION 3.10)
project(processing_server LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
cmake_policy(SET CMP0079 NEW)

set(PROCESSOR_SERVER_SOURCES
    src/main.cpp
    src/handler.cpp
)

add_executable(processing_server ${PROCESSOR_SERVER_SOURCES})

target_include_directories(processing_server PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(processing_server PRIVATE server_lib)
