cmake_minimum_required(VERSION 3.12)
project(cube-factory VERSION 1.0.0 LANGUAGES CXX)
find_package(atta 0.0.0.3 REQUIRED)

atta_add_target(cubeScript "src/cubeScript.cpp")
