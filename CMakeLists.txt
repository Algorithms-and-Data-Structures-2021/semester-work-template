cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# Project name
project(project_name)

# C++ standard specification
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add executables
add_executable(main main.cpp)
