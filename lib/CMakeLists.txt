add_library(euler SHARED 
    input.cpp
    poker.cpp
    prime.cpp
    util.cpp
)
target_include_directories(euler PUBLIC ${CMAKE_SOURCE_DIR}/include)
