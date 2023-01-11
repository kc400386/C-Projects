cmake_minimum_required(VERSION 3.22)
project(solder_example)

set(CMAKE_CXX_STANDARD 17)

add_executable(solder_example Character.cpp Character.h solder_example_pre.cpp)
