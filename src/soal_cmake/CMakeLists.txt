cmake_minimum_required(VERSION 3.10)
project(robot)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable(robot
    src/main.cpp
    src/robot.cpp
    src/robotair.cpp
)