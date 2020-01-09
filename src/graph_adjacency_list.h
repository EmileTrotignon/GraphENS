/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┯━ / ━━━━━━|━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓*/
/*┃ <adjacency_list.h>                                 │ /\ /‾ /\ | /\ ▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁*/
/*┃                                                    │ \_ \_ \/ | \_ ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔*/
/*┃ <created by E.Trotignon and C.Devatine>            │                                                             ┃*/
/*┃                                                    │              _  |                                           ┃*/
/*┃ <date : 10/12/2019>                                │ |\ /\ |‾ |\\ _\ | /\ ▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁*/
/*┃                                                    │ || \/ |  ||| \| | \_ ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔*/
/*┃                                                    │                                                             ┃*/
/*┃                                                    │  _        /    o                                            ┃*/
/*┃                                                    │ /_ || |\ /\ |‾ | /\ || |‾ /\ ▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁*/
/*┃                                                    │ _/ \| |/ \_ |  | \_ \| |  \_ ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔*/
/*┃                                                    │       |                                                     ┃*/
/*┃                                                    │    _     o  _       _ _     | _                             ┃*/
/*┃                                                    │ |\ _\ |‾ | /_ ▁▁▁▁ /_ _\ /‾ | _\\  / ▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁*/
/*┃                                                    │ |/ \| |  | _/ ▔▔▔▔ _/ \| \_ | \| \/  ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔*/
/*┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┷━|━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ / ━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#pragma once


#include <unordered_map>
#include <unordered_set>

#include "graph_types.h"

namespace GraphENS
{
	class graph_adjacency_list
	{
	public:
		using this_t = graph_adjacency_list;
		using neighbors_t = std::unordered_set<neighbor_t>;

		using graph_t = std::unordered_map<vertex_t, neighbors_t>;

		using vertex_iterator = graph_t::iterator;
		using const_vertex_iterator = graph_t::const_iterator;

		graph_adjacency_list() = default;

		size_t size() const;
		// degree
		vertex_t add_vertex();
		edge_t &add_edge(vertex_t, vertex_t);
		// delete vertex
		bool are_neighbors(vertex_t, vertex_t) const;
		neighbors_t neighbors_of(vertex_t) const;

	private:
		graph_t graph;
	};
}