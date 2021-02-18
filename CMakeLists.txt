cmake_minimum_required(VERSION 3.19)

project(hermes_tcp)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE hermes_srcs "*.c" "*.h")

add_library(hermes_tcp STATIC ${hermes_srcs})
set_target_properties(hermes_tcp PROPERTIES PUBLIC_HEADER "include/hermes_tcp.h")

install(TARGETS hermes_tcp 
        LIBRARY DESTINATION lib
        PUBLIC_HEADER DESTINATION include
)

add_subdirectory(test)
