cmake_minimum_required(VERSION 3.15)
project(GraphENS)

set(HEADERS
        src/library.h
        src/Graph.h
        src/searches.h
        src/adjacency_list.h
        src/container_helpers.h
)

set(
        SOURCES
        src/library.cpp
        src/Graph.cpp
)

set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Xclang -fconcepts-ts")
add_library(GraphENS ${SOURCES} ${HEADERS})