cmake_minimum_required(VERSION 3.14)
project(isprime_tests)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(test_isprime test_isprime.cpp)
target_link_libraries(test_isprime gtest_main)
