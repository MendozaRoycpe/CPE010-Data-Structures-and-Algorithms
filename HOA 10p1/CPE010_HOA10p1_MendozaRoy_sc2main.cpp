
#include <iostream>
#include "CPE010_HOA10p1_MendozaRoy_sc1_jiraph.h"

void test_ILO_A() {
    std::cout << "      ILO A: Adjacency List Output      \n";

    GraphEdge<int> edges[] = {
        {0, 1, 2}, {0, 2, 4}, {1, 4, 3}, {2, 3, 2}, {3, 1, 4}, {4, 3, 3}
    };
    int N = 6;
    int n = sizeof(edges) / sizeof(edges[0]);

    DiaGraph<int> diagraph(edges, n, N);
    diagraph.display_AdjList();
    std::cout << std::endl;
}

template <typename T>
void test_DFS() {
    std::cout << "       ILO B.1: Depth-First Search      \n";

    auto G = create_reference_graph<T>();
    std::cout << "Graph Representation:\n" << G << std::endl;

    std::cout << "DFS Order of vertices (starting from ID 1):\n";
    auto dfs_visit_order = depth_first_search(G, 1);
    for (auto v : dfs_visit_order)
        std::cout << v << " ";
    std::cout << "\n\n";
}

template <typename T>
void test_BFS() {
    std::cout << "      ILO B.2: Breadth-First Search     \n";

    auto G = create_reference_graph<T>();

    std::cout << "BFS Order of vertices (starting from ID 1):\n";
    auto bfs_visit_order = breadth_first_search(G, 1);
    for (auto v : bfs_visit_order)
        std::cout << v << " ";
    std::cout << "\n\n";
}

int main() {
    using T = unsigned;

    // Run tests
    test_ILO_A();
    test_DFS<T>();
    test_BFS<T>();

    return 0;
}