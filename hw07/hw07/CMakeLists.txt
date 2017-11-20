cmake_minimum_required(VERSION 3.8)
project(hw07)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        adjmatrix-deep.txt
        adjmatrix-width.txt
        adjmatrix.txt
        graphlib.h
        main.c
        utils.h)

add_executable(hw07 ${SOURCE_FILES})