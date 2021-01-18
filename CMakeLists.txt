cmake_minimum_required(VERSION 3.16)
project(CP)

file(GLOB TASKS "tasks/*.cpp")
file(GLOB_RECURSE HEADERS "library/*.hpp")

add_executable(output output/main.cpp)
add_executable(test ${TASKS} ${HEADERS})
add_executable(testrunner testrunner/main.cpp)