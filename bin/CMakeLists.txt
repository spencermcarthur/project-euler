add_compile_options(-Wall -Wextra -Wpedantic -Werror)

if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    add_compile_options(-ggdb3 -O0)
else()
    add_compile_options(-Ofast)
endif()

link_libraries(euler)

foreach(N RANGE 1 50)
    if(EXISTS ${CMAKE_SOURCE_DIR}/src/0001_0050/${N}.cpp)
        add_executable(${N} ${CMAKE_SOURCE_DIR}/src/0001_0050/${N}.cpp)
    endif()
endforeach()

foreach(N RANGE 51 100)
    if(EXISTS ${CMAKE_SOURCE_DIR}/src/0051_0100/${N}.cpp)
        add_executable(${N} ${CMAKE_SOURCE_DIR}/src/0051_0100/${N}.cpp)
    endif()
endforeach()
