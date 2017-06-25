cmake_minimum_required(VERSION 3.8)
project(cmake_example)

add_subdirectory(pybind11)
pybind11_add_module(cmake_example src/main.cpp)
