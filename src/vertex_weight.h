//
// Created by devatine on 09/01/2020.
//

#ifndef GRAPHENS_VERTEX_WEIGHT_H
#define GRAPHENS_VERTEX_WEIGHT_H

#include "graph_types.h"

#include <unordered_map>

namespace GraphENS
{
	template<typename weight_t>
	class vertex_weight {
	public:
		using weights_t = std::unordered_map<vertex_t, weight_t>;

		explicit vertex_weight(weight_t);

		weight_t&       operator[](vertex_t);
		const weight_t& operator[](vertex_t) const;
	private:
		weights_t weights;
		weight_t default_weight;
	};

	template<typename weight_t>
	vertex_weight<weight_t>::vertex_weight(weight_t w) : default_weight(w)
	{
	}

	template<typename weight_t>
	weight_t& vertex_weight<weight_t>::operator[](const vertex_t v) {
		try
		{
			return weights.at(v);
		}
		catch (std::out_of_range&)
		{
			return weights[v] = default_weight;
		}
	}

	template<typename weight_t>
	const weight_t& vertex_weight<weight_t>::operator[](const vertex_t v) const {
		try
		{
			return weights.at(v);
		}
		catch (std::out_of_range&)
		{
			return default_weight;
		}
	}
}

#endif //GRAPHENS_VERTEX_WEIGHT_H
