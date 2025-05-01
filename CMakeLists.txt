cmake_minimum_required(VERSION 3.10)

project(ProjectEuler)

add_compile_definitions(-DINPUT_DIR="${CMAKE_SOURCE_DIR}/input")

file(COPY ${CMAKE_SOURCE_DIR}/scripts DESTINATION ${CMAKE_BINARY_DIR})

add_subdirectory(bin)
