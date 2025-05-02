include_directories(${CMAKE_SOURCE_DIR}/include)

add_compile_options(-Wall -Wextra -Wpedantic -Werror)

if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    add_compile_options(-ggdb3 -O0)
else()
    add_compile_options(-Ofast)
endif()

foreach(N RANGE 1 30)
    add_executable(${N} ${CMAKE_SOURCE_DIR}/src/${N}.cpp)
    target_link_libraries(${N} euler)
endforeach()
