cmake_minimum_required(VERSION 3.17)
project(OpenMPLabs LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenMP REQUIRED)
find_package(TBB REQUIRED tbb)
add_executable(OpenMPLabs main.cpp task.cpp)
add_subdirectory(log_duration)
add_subdirectory(rand_int)
target_link_libraries(OpenMPLabs PRIVATE OpenMP::OpenMP_CXX RandInt LOG_DURATION TBB::tbb)
target_compile_options(OpenMPLabs PUBLIC -ltbb)
