//
// Created by emile on 09/12/2019.
//

#ifndef GRAPHENS_SEARCHES_H
#define GRAPHENS_SEARCHES_H

#include "graph_types.h"

#include "vertex_weight.h"

namespace GraphENS
{
	enum class color_t {
		white,
		grey,
		black
	};

	template<typename graph_t>
	void depth_first_search(graph_t graph, vertex_t start, predicate<vertex_t, graph_t&>& continue_pred = [](vertex_t v, graph_t& g){ return true; });

	template<typename graph_t>
	void depth_first_search(graph_t graph, vertex_t start, predicate<vertex_t, graph_t &> &continue_pred) {
		vertex_weight<color_t > weights(color_t::white);

		weights[start] = color_t::black;

		std::function<void(vertex_t)> depth_first_search_internal = [&depth_first_search_internal, &weights, &graph, &continue_pred, start](vertex_t current) -> void {
			for (neighbor_t neighbor : graph.neighbors_of(start))
			{
				if (weights[current] == color_t::black)
					return;
				weights[current] = color_t::black;
				if (continue_pred(neighbor, graph)) {
					depth_first_search_internal(neighbor);
				}
			}
		};

		depth_first_search_internal(start);
	}




}

#endif //GRAPHENS_SEARCHES_H
