cmake_minimum_required(VERSION 3.10)  
project(test_project LANGUAGES CXX)

cmake_policy(SET CMP0079 NEW)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(client_app)
add_subdirectory(display_server)
add_subdirectory(processing_server)
add_subdirectory(server_lib)
