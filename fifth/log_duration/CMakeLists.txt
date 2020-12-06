cmake_minimum_required(VERSION 3.17)
project(LOG_DURATION LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_library(LOG_DURATION profile.h)
set_target_properties(LOG_DURATION PROPERTIES LINKER_LANGUAGE CXX)
