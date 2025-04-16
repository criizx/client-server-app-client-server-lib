cmake_minimum_required(VERSION 3.10)
project(client_app LANGUAGES CXX)
cmake_policy(SET CMP0079 NEW)

set(CLIENT_APP_SOURCES
    src/main.cpp
)

add_executable(client_app ${CLIENT_APP_SOURCES})

target_link_libraries(client_app PRIVATE server_lib)