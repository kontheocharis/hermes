cmake_minimum_required(VERSION 3.19)

project(hermes_tcp)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
        set(TARGET_PLATFORM "macos")
else()
        message(FATAL_ERROR "The operating system '${CMAKE_SYSTEM_NAME}' is not currently supported" )
endif()

add_subdirectory(src)
add_subdirectory(test)
