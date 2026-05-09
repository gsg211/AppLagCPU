cmake_minimum_required(VERSION 4.2)
project(amd_applag)

set(CMAKE_CXX_STANDARD 23)

add_executable(amd_applag main.cpp
        Constants.h
        src/Memory/memory.cpp
        src/Timing/Timing.h
        src/Timing/Timing.cpp
        src/Registers/RegisterBank.h
        src/Registers/RegisterBank.cpp
)

target_include_directories(amd_applag PRIVATE
        ${CMAKE_SOURCE_DIR}/src/cpu/Decoder
        ${CMAKE_SOURCE_DIR}/src/cpu
        ${CMAKE_SOURCE_DIR}/src/Memory
        ${CMAKE_SOURCE_DIR}/src/Registers
        ${CMAKE_SOURCE_DIR}/src/Timing
)
