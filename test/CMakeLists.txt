find_package(GTest REQUIRED)

add_executable(util EXCLUDE_FROM_ALL util.cpp)
target_link_libraries(util PUBLIC GTest::gtest GTest::gtest_main euler)
target_compile_options(util PUBLIC -O0)
