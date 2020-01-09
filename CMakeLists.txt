cmake_minimum_required(VERSION 3.15)
project(GraphENS)

set(HEADERS
        src/graph_types.h
        src/container_helpers.h
        src/graph_adjacency_list.h
        src/vertex_weight.h
        src/searches.h
        src/library.h

        src/graph.h
)

set(
        SOURCES
        src/graph_adjacency_list.cpp
)

set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Xclang -fconcepts-ts")
add_library(GraphENS ${SOURCES} ${HEADERS})