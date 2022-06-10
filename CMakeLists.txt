cmake_minimum_required(VERSION 3.19)
project(dlib)

set(CMAKE_CXX_STANDARD 14)

add_executable(dlib Graph.cc Graph.h main.cpp)