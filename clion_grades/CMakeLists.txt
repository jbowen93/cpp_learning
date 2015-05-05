cmake_minimum_required(VERSION 3.1)
project(clion_grades)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp median.cpp read.cpp grade.cpp)
add_executable(clion_grades ${SOURCE_FILES})