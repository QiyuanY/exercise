cmake_minimum_required(VERSION 3.19)
project(dlib)

set(CMAKE_CXX_STANDARD 14)

add_executable(dlib  Graph.h Graph.cc FileRead.cc FileRead.h main.cpp)