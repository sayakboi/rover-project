cmake_minimum_required(VERSION 3.10)

project(RoverProject)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES
    rover.cpp
    grid.cpp
    rover.h
    grid.h
    roverio.h
    roverio.cpp
)

# Create the executable
add_executable(RoverProject ${SOURCE_FILES})