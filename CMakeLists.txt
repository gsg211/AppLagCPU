cmake_minimum_required(VERSION 4.2)
project(amd_applag)

set(CMAKE_CXX_STANDARD 23)

add_executable(amd_applag src/main.cpp
        src/Timing/Timing.cpp
        src/Timing/Timing.h
)

target_include_directories(amd_applag PRIVATE ${CMAKE_SOURCE_DIR})
target_include_directories(amd_applag PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_include_directories(amd_applag PRIVATE ${CMAKE_SOURCE_DIR}/src/Timing)

