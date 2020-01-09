//
// Created by devatine on 09/01/2020.
//

#ifndef GRAPHENS_GRAPH_TYPES_H
#define GRAPHENS_GRAPH_TYPES_H

#include <cstddef>

#include <functional>
#include <utility>

using vertex_t = size_t;
using edge_t = std::pair<vertex_t, vertex_t>;
using neighbor_t = vertex_t;

vertex_t create_vertex()
{
	static vertex_t id = 0;
	return id++;
}

template<typename ...T>
using predicate = std::function<bool(T...)>;

#endif //GRAPHENS_GRAPH_TYPES_H
