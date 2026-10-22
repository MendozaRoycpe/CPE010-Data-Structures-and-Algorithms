//
// Created by royga on 9/29/2026.
//
#include <iostream>
#include "graph.h"

int main() {
    Graph g;

    // Adding vertices representing A(0), B(1), C(2), D(3)
    for (int i = 0; i < 4; i++) {
        g.addVertex(i);
    }

    // Add edges with weights
    g.addEdge(0, 1, 3);
    g.addEdge(0, 2, 2);
    g.addEdge(2, 1, 1);
    g.addEdge(3, 0, 4);

    std::cout << "\nGraph Adjacency:\n" << g << std::endl;

    return 0;
}

//reference of this student's code are the codes in module 10.1 Graphs