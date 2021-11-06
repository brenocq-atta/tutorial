cmake_minimum_required(VERSION 3.12)
project(simple-script VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# The CMakeLists.txt lists all scripts that will be exposed to the atta.
# This example creates one project script: projectScript
# and two entity scripts: cubeScript and lightScript

# Create project script target
add_library(projectScript SHARED
    src/projectScript.cpp
)

# Create cube script target
add_library(cubeScript SHARED
    src/cubeScript.cpp
)

# Create light script target
add_library(lightScript SHARED
    src/lightScript.cpp
)
