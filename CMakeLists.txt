cmake_minimum_required(VERSION 3.15)
project(GraphENS)

set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Xclang -fconcepts-ts")
add_library(GraphENS src/library.cpp src/library.h src/Graph.cpp src/Graph.h src/searches.cpp src/searches.h)