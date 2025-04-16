cmake_minimum_required(VERSION 3.10)
project(server_lib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(server_lib STATIC 
    server_lib.cpp
    server_lib.hpp
    validator.cpp
    validator.hpp
)
target_include_directories(server_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
