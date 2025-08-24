cmake_minimum_required(VERSION 4.0)
project(TikTakTo_Minimax)

set(CMAKE_CXX_STANDARD 20)

add_executable(TikTakTo_Minimax main.cpp
        Spielfeld.cpp
        Spielfeld.h
        MiniMax.cpp
        MiniMax.h)
