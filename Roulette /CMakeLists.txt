cmake_minimum_required(VERSION 3.29)
project(Roulette_)

set(CMAKE_CXX_STANDARD 20)

add_executable(Roulette_ main.cpp
        Wheel.cpp
        Player.cpp
)
