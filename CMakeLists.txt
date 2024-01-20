cmake_minimum_required(VERSION 3.10)

project(MemoryManagerSimulator)

add_executable(MemoryManagerSimulator MemoryManager.cpp main.cpp)

add_custom_command(TARGET MemoryManagerSimulator POST_BUILD
    COMMAND $<TARGET_FILE:MemoryManagerSimulator>
)
