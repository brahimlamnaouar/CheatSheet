cmake_minimum_required(VERSION 3.15)
project(CheatSheet)

set(CMAKE_CXX_STANDARD 14)

add_library(CheatSheet library.cpp stl.cpp library.h)