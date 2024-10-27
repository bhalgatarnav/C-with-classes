cmake_minimum_required(VERSION 3.29)
project(War)

set(CMAKE_CXX_STANDARD 20)

add_executable(War main.cpp
        Deck.cpp
        SidePile.cpp)
