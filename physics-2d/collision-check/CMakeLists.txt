cmake_minimum_required(VERSION 3.14)
project(collision-check VERSION 1.0.0 LANGUAGES CXX)
find_package(atta 0.4.0.0 REQUIRED)

atta_add_target(projectScript "src/projectScript.cpp")
