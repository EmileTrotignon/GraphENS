//
// Created by devatine on 09/01/2020.
//

#include "graph_adjacency_list.h"

#include "container_helpers.h"

namespace GraphENS
{
	size_t graph_adjacency_list::size() const {
		return graph.size();
	}

	vertex_t graph_adjacency_list::add_vertex() {
		vertex_t v = generate_id();
		graph.insert(v);

		return v;
	}

	edge_t &graph_adjacency_list::add_edge(vertex_t v1, vertex_t v2) {
		graph.at(v1).insert(v2);

		return std::make_pair(v1, v2);
	}

	bool graph_adjacency_list::are_neighbors(vertex_t v1, vertex_t v2) const {
		return contains(graph.at(v1), v2);
	}

	graph_adjacency_list::neighbors_t graph_adjacency_list::neighbors_of(vertex_t v) const {
		return graph.at(v);
	}
}