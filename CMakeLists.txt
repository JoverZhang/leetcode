cmake_minimum_required(VERSION 3.25)

project(leetcode LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_C_STANDARD 23)

include_directories(include)

add_subdirectory(src)
add_subdirectory(include)
