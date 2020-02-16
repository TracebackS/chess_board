cmake_minimum_required(VERSION 3.15)
project(chessboard_cover C)

set(CMAKE_C_STANDARD 99)

add_executable(chessboard_cover
        src/main.c
        src/datastructure.h
        src/datastructure.c
        src/algorithm.c
        src/algorithm.h)