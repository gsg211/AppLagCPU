cmake_minimum_required(VERSION 4.2)
project(amd_applag)

set(CMAKE_CXX_STANDARD 23)

add_executable(amd_applag main.cpp
        Constants.h
        src/Memory/memory.cpp
        src/Timing/Timing.h
        src/Timing/Timing.cpp
        src/Registers/RegisterBank.cpp
        src/cpu/Decoder/Decoder.cpp
        src/cpu/IModule.h
        src/cpu/Data/Execute/Execute.cpp
        src/cpu/Data/Execute/Execute.h
        src/cpu/cpu.cpp
        src/cpu/cpu.h
        src/cpu/Data/Execute/Alu.cpp
        src/cpu/Data/Execute/Alu.h
        src/cpu/Data/Execute/Execute.h
        src/cpu/Data/Execute/Execute.cpp
        src/cpu/Data/Execute/Alu.cpp
        src/cpu/Data/Execute/Alu.h
        src/cpu/cpu.cpp
        src/cpu/cpu.h
        src/cpu/cpu.cpp
        src/cpu/Data/Execute/Alu.cpp
        src/cpu/Data/Execute/Alu.cpp
        src/cpu/ThreadSafeQueue/ThreadSafeQueue.h
        src/cpu/Utils.h
)

target_include_directories(amd_applag PRIVATE
        ${CMAKE_SOURCE_DIR}/src/cpu/Decoder
        ${CMAKE_SOURCE_DIR}/src/cpu
        ${CMAKE_SOURCE_DIR}/src/Memory
        ${CMAKE_SOURCE_DIR}/src/Registers
        ${CMAKE_SOURCE_DIR}/src/Timing
        ${CMAKE_SOURCE_DIR}/src/cpu/Data/Execute
        ${CMAKE_SOURCE_DIR}/src/cpu/Control
        ${CMAKE_SOURCE_DIR}/src
)
