cmake_minimum_required(VERSION 3.12)
project(logging VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Create project script target
add_library(projectScript SHARED
    src/projectScript.cpp
)
