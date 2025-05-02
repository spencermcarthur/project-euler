add_library(euler STATIC 
    ${CMAKE_SOURCE_DIR}/src/input.cpp
    ${CMAKE_SOURCE_DIR}/src/prime.cpp
    ${CMAKE_SOURCE_DIR}/src/util.cpp
)
target_include_directories(euler PUBLIC ${CMAKE_SOURCE_DIR}/include)
