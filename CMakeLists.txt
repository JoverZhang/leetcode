cmake_minimum_required(VERSION 3.16)

project(leetcode)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER c++)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

add_subdirectory(./src)
add_subdirectory(./lib)
