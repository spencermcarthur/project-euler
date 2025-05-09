find_package(benchmark REQUIRED)

add_executable(paired_hash EXCLUDE_FROM_ALL paired_hash.cpp)
target_link_libraries(paired_hash PUBLIC benchmark euler)
target_compile_options(paired_hash PUBLIC -O3)
