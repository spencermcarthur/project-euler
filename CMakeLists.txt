cmake_minimum_required(VERSION 3.10)

project(ProjectEuler)

add_compile_definitions(-DINPUT_DIR="${CMAKE_SOURCE_DIR}/input")
include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(bin)
add_subdirectory(lib)
add_subdirectory(test)
add_subdirectory(benchmark)

file(COPY ${CMAKE_SOURCE_DIR}/scripts 
    DESTINATION ${CMAKE_BINARY_DIR})
