cmake_minimum_required(VERSION 3.3)
project(AAL)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

set(SOURCE_FILES src/main.cpp src/sources/Shelf.cpp src/headers/Shelf.h src/sources/Generator.cpp src/headers/Generator.h src/sources/Benchmark.cpp src/headers/Benchmark.h)
add_executable(AAL ${SOURCE_FILES})