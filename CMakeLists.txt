cmake_minimum_required(VERSION 3.15)
project(GraphENS)

set(HEADERS
        src/library.h
        src/graph.h
        src/adjacency_list.h
        src/container_helpers.h
)

set(
        SOURCES
)

set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Xclang -fconcepts-ts")
#add_library(GraphENS ${SOURCES} ${HEADERS})

add_executable(unit_tests ${SOURCES} ${HEADERS} src/unit_tests.cpp)