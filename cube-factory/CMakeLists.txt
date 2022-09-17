cmake_minimum_required(VERSION 3.14)
project(cube-factory VERSION 1.0.0 LANGUAGES CXX)
find_package(atta 0.2.0.0 REQUIRED)

atta_add_target(cubeScript "src/cubeScript.cpp")
