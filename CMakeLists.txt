cmake_minimum_required(VERSION 4.0)
project(DailyChallenges C CXX)

set(CMAKE_C_STANDARD 99)

# GoogleTest requires at least C++17
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_FLAGS "-Wall -Wextra -Werror -pedantic -std=c99 -Wvla")
set(CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++2a -Wold-style-cast")

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -g3")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g3")
elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
endif ()

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_library(challenge_1 SHARED challenge_1/src/lib.c
        challenge_1/src/lib.h)

add_executable(challenge_1_tests challenge_1/tests/pointer_array_tests.cc
        challenge_1/tests/int_array_tests.cc
        challenge_1/tests/arbitrary_array_tests.cc
        challenge_1/tests/structures.hh)
target_link_libraries(challenge_1_tests challenge_1)
include_directories(.)
target_link_libraries(challenge_1_tests GTest::gtest_main)


