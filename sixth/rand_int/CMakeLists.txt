cmake_minimum_required(VERSION 3.17)
project(RandInt LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_library(RandInt rand.cpp)
