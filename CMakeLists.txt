cmake_minimum_required(VERSION 3.16)
project(data_structure_course)

set(CMAKE_CXX_STANDARD 14)

add_executable(data_structure_course arrayList.cpp)
add_executable(priorityQueue priorityQueue.cpp priorityQueue.h arrayList.cpp arrayList.h)