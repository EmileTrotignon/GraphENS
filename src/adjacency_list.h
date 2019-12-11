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

#include <algorithm>
#include <cstddef>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "container_helpers.h"

namespace GraphENS {

    template<typename VertexWeight = void, typename EdgeWeight = void>
    class adjacency_list {
//		using vertex_t = std::pair<size_t, >
//		using neighbors_t = std::vector<>
//		std::vector<>
    public:

    };

    template<>
    class adjacency_list<void, void> {
        using this_t = adjacency_list<void, void>;

        using id_t = size_t;
        using vertex_t = id_t;
        using neighbor_t = id_t;
        using neighbors_t = std::unordered_set<neighbor_t>;

        std::unordered_map<vertex_t, neighbors_t> graph;

        id_t generate_id() {
            static id_t generated = 0;
            return generated++;
        }

    public:
        adjacency_list<void, void>() = default;

        size_t size() const {
            return graph.size();
        }

        id_t add_vertex() {
            id_t id = generate_id();
            graph.insert(std::make_pair(id, neighbors_t ()));
            return id;
        }

        bool add_edge(id_t from, id_t to) {
            auto it = std::find(graph.begin(), graph.end(), [from](auto x) { return x == from; });
            auto [_, inserted] = graph.at(it->first).insert(to);
            return inserted;
        }

        void set_weight() {
            // TODO
            return;
        }

        // Delete the vertex and all edges connected to it
        void erase_vertex(id_t id) {
            graph.erase(id);
        }

        // Erase edge. Return true if the edge existed and was deleted
        bool erase_edge(id_t from, id_t to) {
            if (contains(graph.at(from), to))
                return false;
            graph.at(from).erase(to);
            return true;
        }

        const std::unordered_set<id_t>& neighbors_of(id_t id) const {
            return graph.at(id);
        }
    };
}
