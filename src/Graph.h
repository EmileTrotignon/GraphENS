//
// Created by emile on 29/11/2019.
//

#ifndef GRAPHENS_GRAPH_H
#define GRAPHENS_GRAPH_H

#include <functional>
#include <queue>
#include <vector>

namespace GraphENS
{
/*template<typename T>
concept GraphDataStructure =
        requires (T t, size_t i, size_t j)
            {
                t.is_edge(i, j);
            }
        &&
                requires (T t, size_t i, size_t j)
                {
                    t.is_edge(i, j);
                };

*/
template <typename DataStructure> class Graph
{
    DataStructure data;
    using vertex_t = typename DataStructure::vertex_t;
    using edge_t = typename DataStructure::edge_t;
    using this_t = Graph<DataStructure>;

public:
    // region data structure access

    bool is_edge(size_t i, size_t j)
    {
        return data.is_edge(i, j);
    }

    edge_t edge_weight(size_t i, size_t j)
    {
        return data.edge_weight(i, j);
    }

    std::vector<size_t> neighbours(size_t i)
    {
        return data.adjacency_list(i);
    }

    size_t size()
    {
        return data.size();
    }

    void add_vertex()
    {
        data.add_vertex();
    }

    void set_vertex_weight()
    {
    }

    void set_edge_weight()
    {
    }

    void add_edge(vertex_t i, vertex_t j,
                  edge_t weight = DataStructure::default_edge_weight)
    {
        std::function<bool(std::vector<int>)> f;
        data.add_edge(i, j);
    }

    // endregion

    // region algorithms

private:
    void depth_first_search_aux(
        size_t start,
        const std::function<void(const Graph<DataStructure> &, size_t)> &f,
        const std::function<bool(size_t, const this_t &)> &continue_predicate,
        std::vector<bool> &visited) const
    {
        if (!visited.at(start))
        {
            visited.at(start) = true;
            f(*this, start);
            if (continue_predicate(start, *this))
            {
                for (auto vertex : neighbours())
                {
                    depth_first_search_aux(vertex, f, continue_predicate,
                                           visited);
                }
            }
        }
    }

public:
    void depth_first_search(
        size_t start,
        const std::function<void(const Graph<DataStructure> &, size_t)> &f,
        const std::function<bool(size_t, const this_t &)> &continue_predicate)
    {
        std::vector<bool> visited(size(), false);
        depth_first_search_aux(start, f, continue_predicate, visited);
    }

    void breadth_first_search(
        size_t start,
        const std::function<void(const Graph<DataStructure> &, size_t)> &f,
        const std::function<bool(size_t, const this_t &)> &continue_predicate,
        std::vector<bool> &visited) const
    {
        std::queue<size_t> queue;
        queue.push(start);
        while (!queue.empty())
        {
            size_t vertex = queue.front();
            visited.at(vertex) = true;
            if (continue_predicate(vertex, *this))
            {
                for (auto v : neighbours(vertex))
                {
                    if (!visited.at(vertex))
                    {
                        queue.push(v);
                    }
                }
            }
        }
    }

    // endregion
};

} // namespace GraphENS

#endif // GRAPHENS_GRAPH_H
