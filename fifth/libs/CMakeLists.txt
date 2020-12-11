cmake_minimum_required(VERSION 3.17)
project(LOG_DURATION LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_library(CppConsoleTable CppConsoleTable.hpp)
set_target_properties(CppConsoleTable PROPERTIES LINKER_LANGUAGE CXX)
