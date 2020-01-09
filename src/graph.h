/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┯━ / ━━━━━━|━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓*/
/*┃ <graph.h>                                          │ /\ /‾ /\ | /\ ▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁*/
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

#include <functional>
#include <queue>
#include <set>
#include <tuple>
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
template <typename DataStructure> class graph
{
    DataStructure data;

    using vertex_t = typename DataStructure::vertex_t;
    using edge_t = typename DataStructure::edge_t;
    using this_t = graph<DataStructure>;
    using neighbors_t = typename DataStructure::neighbours_t;

public:
    // region data structure access

    bool is_edge(size_t i, size_t j) const
    {
        return data.is_edge(i, j);
    }

    edge_t edge_weight(size_t i, size_t j) const
    {
        return data.edge_weight(i, j);
    }

    const neighbors_t &neighbors(size_t i) const
    {
        return data.adjacency_list(i);
    }

    size_t size() const
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

    void add_edge(vertex_t i, vertex_t j, edge_t weight = DataStructure::default_edge_weight)
    {
        std::function<bool(std::vector<int>)> f;
        data.add_edge(i, j);
    }

    // endregion

    // region algorithms

private:
    void depth_first_search_aux(size_t prev, size_t start, const std::function<void(size_t, size_t, const this_t &)> &f,
                                const std::function<bool(size_t, size_t, const this_t &)> &continue_predicate,
                                std::vector<bool> &visited) const
    {
        if (!visited.at(start))
        {
            visited.at(start) = true;
            f(prev, start, *this);
            if (continue_predicate(prev, start, *this))
            {
                for (auto vertex : neighbors())
                {
                    depth_first_search_aux(start, vertex, f, continue_predicate, visited);
                }
            }
        }
    }

public:
	template<typename Graph_T>
    void depth_first_search(
        size_t start, const std::function<void(const graph<DataStructure> &, size_t)> &f,
        const std::function<bool(size_t, const this_t &)> &continue_predicate = [](size_t, const this_t &) {
            return true;
        }) const
    {
        std::vector<bool> visited(size(), false);
        depth_first_search_aux(start, start, f, continue_predicate, visited);
    }

    void breadth_first_search(
        size_t prev, size_t start, const std::function<void(size_t, size_t, const this_t &)> &f,
        const std::function<bool(size_t, size_t, const this_t &)> &continue_predicate =
            [](size_t, size_t, const this_t &) { return true; }) const
    {
        std::vector<bool> visited(size(), false);
        std::queue<std::tuple<size_t, size_t>> queue;
        queue.push({start, start});
        while (!queue.empty())
        {
            auto [prev, vertex] = queue.front();
            f(prev, vertex, *this);
            visited.at(vertex) = true;
            if (continue_predicate(prev, vertex, *this))
            {
                for (auto v : neighbors(vertex))
                {
                    if (!visited.at(vertex))
                    {
                        queue.push({vertex, v});
                    }
                }
            }
        }
    }

private:
    class q_elem : public std::tuple<size_t, const double &>
    {
        bool operator>(const q_elem &other)
        {
            return std::get<1>(*this) > std::get<1>(other);
        }
    };

public:
    template <
        template <class T, class Container = std::vector<T>, class Compare = std::less<typename Container::value_type>>
        typename PriorityQueue,
        const std::function<double(const this_t &, size_t, size_t)> &distance>
    std::vector<size_t> dijkstra(
        size_t start, const std::function<bool(size_t, const this_t &)> &continue_predicate =
                          [](size_t, const this_t &) { return true; }) const
    {
        PriorityQueue<q_elem, std::vector<q_elem>, std::greater<q_elem>> queue;
        std::vector<size_t> predecessors(size(), -1);
        std::vector<double> distances(size(), std::numeric_limits<double>::infinity());
        distances.at(start) = 0;

        for (size_t v = 0; v < size(); v++)
        {
            queue.push({v, distances.at(v)});
        }
        while (!queue.empty())
        {
            auto [vertex, _] = queue.pop();
            for (auto v : neighbors(vertex))
            {
                double candidate_dist = distances[vertex] + distance(*this, vertex, v);
                if (candidate_dist < distances[v])
                {
                    distances[v] = candidate_dist;
                    predecessors[v] = vertex;
                }
            }
        }
        return predecessors;
    }

    std::vector<std::vector<size_t>> tarjan()
    {

    }

    // endregion

};

} // namespace GraphENS
