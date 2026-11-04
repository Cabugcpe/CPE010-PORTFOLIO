#ifndef GRAPH_H
#define GRAPH_H

template <typename T>
struct Edge
{
    size_t src;
    size_t dest;
    T weight;
};

template <typename T>
class Graph
{
private:
    size_t V;
    std::vector<Edge<T>> edge_list;

public:
    Graph(size_t N) : V(N) {}

    void add_edge(Edge<T>&& e)
    {
        edge_list.push_back(e);
    }

    auto outgoing_edges(size_t v) const
    {
        std::vector<Edge<T>> edges_from_v;

        for (const auto& e : edge_list)
        {
            if (e.src == v)
            {
                edges_from_v.push_back(e);
            }
        }

        return edges_from_v;
    }

    auto vertices() const
    {
        return V;
    }
};

template <typename T>
Graph<T> create_reference_graph()
{
    Graph<T> G(9);

    std::map<unsigned,
    std::vector<std::pair<size_t, T>>> edges;

    edges[1] = {{2,0}, {5,0}};
    edges[2] = {{1,0}, {5,0}, {4,0}};
    edges[3] = {{4,0}, {7,0}};
    edges[4] = {{2,0}, {3,0}, {5,0}, {6,0}, {8,0}};
    edges[5] = {{1,0}, {2,0}, {4,0}, {8,0}};
    edges[6] = {{4,0}, {7,0}, {8,0}};
    edges[7] = {{3,0}, {6,0}};
    edges[8] = {{4,0}, {5,0}, {6,0}};

    for (auto& i : edges)
    {
        for (auto& j : i.second)
        {
            G.add_edge(
                Edge<T>{i.first, j.first, j.second}
            );
        }
    }

    return G;
}

// B.1
template <typename T>
std::vector<size_t> depth_first_search(const Graph<T>& G)
{
    std::stack<size_t> stack;
    std::vector<size_t> visit_order;
    std::set<size_t> visited;

    stack.push(1);

    while (!stack.empty())
    {
        auto current_vertex = stack.top();
        stack.pop();

        if (visited.find(current_vertex) == visited.end())
        {
            visited.insert(current_vertex);
            visit_order.push_back(current_vertex);

            for (auto e : G.outgoing_edges(current_vertex))
            {
                if (visited.find(e.dest) == visited.end())
                {
                    stack.push(e.dest);
                }
            }
        }
    }

    return visit_order;
}

// B.2
template <typename T>
std::vector<size_t> breadth_first_search(const Graph<T>& G)
{
    std::queue<size_t> queue;
    std::vector<size_t> visit_order;
    std::set<size_t> visited;

    queue.push(1);

    while (!queue.empty())
    {
        auto current_vertex = queue.front();
        queue.pop();

        if (visited.find(current_vertex) == visited.end())
        {
            visited.insert(current_vertex);
            visit_order.push_back(current_vertex);

            for (auto e : G.outgoing_edges(current_vertex))
            {
                queue.push(e.dest);
            }
        }
    }

    return visit_order;
}

#endif