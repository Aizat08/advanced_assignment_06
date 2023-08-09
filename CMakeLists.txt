cmake_minimum_required (VERSION 2.8.11)
project(matrix)

add_executable(matrix main.cpp)
set_target_properties(matrix PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQUIRED ON)
