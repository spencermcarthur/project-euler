include_directories(${CMAKE_SOURCE_DIR}/include)

if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    add_compile_options(-ggdb3 -O0)
else()
    add_compile_options(-Ofast)
endif()

foreach(N RANGE 1 25)
    add_executable(${N} ${CMAKE_SOURCE_DIR}/src/${N}.cpp)
endforeach()
