#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include "graph.h"

int main(){

    // ILO B1
    Graph<unsigned> G =
        create_reference_graph<unsigned>();

    std::cout << "DFS Order of vertices:" << std::endl;
    auto dfs = depth_first_search(G);

    for (auto vertex : dfs)
    {
        std::cout << vertex << " ";
    }
    

    // ILO B2
    std::cout << "\n\n";
    std::cout << "BFS Order of vertices:" << std::endl;
    auto bfs = breadth_first_search(G);

    for (auto vertex : bfs)
    {
        std::cout << vertex << " ";
    }

    std::cout << std::endl;

    return 0;
}