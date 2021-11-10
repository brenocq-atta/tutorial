cmake_minimum_required(VERSION 3.12)
project(cube-factory VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# This time we are only using one entity script
add_library(cubeScript SHARED
    src/cubeScript.cpp
)
