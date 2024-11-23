cmake_minimum_required(VERSION 3.29)

# Project definition
project(Homework3 VERSION 1.0 LANGUAGES CXX)

# Set C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add main executable
add_executable(Homework3
        main.cpp
        HashFunc/HashTableLP.h
        HashFunc/HashTable2D.h
)

# Include directories for headers
target_include_directories(Homework3 PRIVATE HashFunc)

# Add Google Tests
add_subdirectory(Google_tests)
# Add the HashFunc_lib directory to the build
add_subdirectory(HashFunc)


# Link Google Test libraries to the main executable
target_link_libraries(Homework3 PRIVATE gtest gtest_main)