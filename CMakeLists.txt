cmake_minimum_required(VERSION 4.1)
project(minesweeper)

set(CMAKE_CXX_STANDARD 20)

add_executable(minesweeper main.cpp TerminalGuard.h
        FieldGenerator.cpp
        FieldGenerator.h
        TerminalGuard.cpp)
