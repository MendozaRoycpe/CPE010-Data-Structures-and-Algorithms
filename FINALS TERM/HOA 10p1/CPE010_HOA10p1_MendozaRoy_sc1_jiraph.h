//
// Created by royga on 10/1/2026.
//

#ifndef UNTITLED1_JIRAPH_H
#define UNTITLED1_JIRAPH_H

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
//ILO A: Graph Implementation (Adjacency List & Adjacency Matrix)
template <typename T>
struct AdjNode {
    T val;
    T cost;
    AdjNode<T>* next;
};

template <typename T>
struct GraphEdge {
    int start_ver;
    int end_ver;
    T weight;
};

template <typename T>
class DiaGraph {
private:
    int N;

    AdjNode<T>* getAdjListNode(T value, T weight, AdjNode<T>* head) {
        AdjNode<T>* newNode = new AdjNode<T>;
        newNode->val = value;
        newNode->cost = weight;
        newNode->next = head;
        return newNode;
    }

public:
    AdjNode<T>** head;

    DiaGraph(GraphEdge<T> edges[], int n, int N) {
        head = new AdjNode<T>*[N]();
        this->N = N;

        for (int i = 0; i < N; ++i)
            head[i] = nullptr;

        for (int i = 0; i < n; i++) {
            int start_ver = edges[i].start_ver;
            int end_ver = edges[i].end_ver;
            T weight = edges[i].weight;

            AdjNode<T>* newNode = getAdjListNode(static_cast<T>(end_ver), weight, head[start_ver]);
            head[start_ver] = newNode;
        }
    }

    /*
    // ORIGINAL DESTRUCTOR
    ~DiaGraph() {
        for (int i = 0; i < N; i++)
            delete[] head[i];
        delete[] head;
    }
    */

    ~DiaGraph() {
        for (int i = 0; i < N; i++) {
            AdjNode<T>* current = head[i];
            while (current != nullptr) {
                AdjNode<T>* next = current->next;
                delete current;
                current = next;
            }
        }
        delete[] head;
    }

    // Copying would make two objects free the same nodes (double free)
    DiaGraph(const DiaGraph&) = delete;
    DiaGraph& operator=(const DiaGraph&) = delete;

    void display_AdjList() const {
        std::cout << "Graph adjacency list\n(start_vertex, end_vertex, weight):\n";
        for (int i = 0; i < N; i++) {
            AdjNode<T>* ptr = head[i];
            while (ptr != nullptr) {
                std::cout << "(" << i << ", " << ptr->val << ", " << ptr->cost << ") ";
                ptr = ptr->next;
            }
            std::cout << std::endl;
        }
    }
};

// ILO A.2: Adjacency Matrix Representation
template <typename T>
class AdjMatrixGraph {
private:
    int V;
    std::vector<std::vector<T>> matrix;

public:
    AdjMatrixGraph(int vertices) : V(vertices), matrix(vertices, std::vector<T>(vertices, 0)) {}

    void add_edge(int src, int dest, T weight = 1) {
        if (src >= 0 && src < V && dest >= 0 && dest < V) {
            matrix[src][dest] = weight;
        }
    }

    void display_matrix() const {
        std::cout << "Adjacency Matrix:\n";
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << "\n";
        }
    }
};

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//ILO B: Graph Traversal Algorithms (Edge-List Representation)
template <typename T>
struct Edge {
    size_t src;
    size_t dest;
    T weight;

    inline bool operator<(const Edge<T> &e) const {
        return this->weight < e.weight;
    }
    inline bool operator>(const Edge<T> &e) const {
        return this->weight > e.weight;
    }
};

template <typename T>
class Graph {
private:
    size_t V;
    std::vector<Edge<T>> edge_list;

public:
    Graph(size_t N) : V(N) {}

    auto vertices() const {
        return V;
    }

    auto &edges() const {
        return edge_list;
    }

    void add_edge(Edge<T> &&e) {
        if (e.src >= 1 && e.src <= V && e.dest >= 1 && e.dest <= V)
            edge_list.emplace_back(e);
        else
            std::cerr << "Vertex out of bounds" << std::endl;
    }

    auto outgoing_edges(size_t v) const {
        std::vector<Edge<T>> edges_from_v;
        for (auto &e : edge_list) {
            if (e.src == v)
                edges_from_v.emplace_back(e);
        }
        return edges_from_v;
    }

    template <typename U>
    friend std::ostream &operator<<(std::ostream &os, const Graph<U> &G);
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const Graph<T> &G) {
    // for (size_t i = 1; i < G.vertices(); i++) {
    for (size_t i = 1; i <= G.vertices(); i++) {
        os << i << ":\t";
        auto edges = G.outgoing_edges(i);
        for (auto &e : edges)
            os << "{" << e.dest << ": " << e.weight << "}, ";
        os << std::endl;
    }
    return os;
}

// B.1. Depth-First Search
template <typename T>
auto depth_first_search(const Graph<T> &G, size_t start_vertex) {
    std::stack<size_t> stack;
    std::vector<size_t> visit_order;
    std::set<size_t> visited;

    stack.push(start_vertex);
    while (!stack.empty()) {
        auto current_vertex = stack.top();
        stack.pop();

        if (visited.find(current_vertex) == visited.end()) {
            visited.insert(current_vertex);
            visit_order.push_back(current_vertex);

            auto edges = G.outgoing_edges(current_vertex);
            for (auto it = edges.rbegin(); it != edges.rend(); ++it) {
                if (visited.find(it->dest) == visited.end()) {
                    stack.push(it->dest);
                }
            }
        }
    }
    return visit_order;
}

// B.2. Breadth-First Search
template <typename T>
auto breadth_first_search(const Graph<T> &G, size_t start_vertex) {
    std::queue<size_t> queue;
    std::vector<size_t> visit_order;
    std::set<size_t> visited;

    queue.push(start_vertex);
    visited.insert(start_vertex);

    while (!queue.empty()) {
        auto current_vertex = queue.front();
        queue.pop();
        visit_order.push_back(current_vertex);

        /*
        for (auto e : G.outgoing_edges(current_vertex))
            queue.push(e.dest);
        */
        // for (auto e : G.outgoing_edges(current_vertex)) {
        auto edges = G.outgoing_edges(current_vertex);
        for (auto &e : edges) {
            if (visited.find(e.dest) == visited.end()) {
                visited.insert(e.dest);
                queue.push(e.dest);
            }
        }
    }
    return visit_order;
}

template <typename T>
auto create_reference_graph() {
    // Graph<T> G(9);
    Graph<T> G(8);
    std::map<unsigned, std::vector<std::pair<size_t, T>>> edges;
    edges[1] = {{2, 0}, {5, 0}};
    edges[2] = {{1, 0}, {5, 0}, {4, 0}};
    edges[3] = {{4, 0}, {7, 0}};
    edges[4] = {{2, 0}, {3, 0}, {5, 0}, {6, 0}, {8, 0}};
    edges[5] = {{1, 0}, {2, 0}, {4, 0}, {8, 0}};
    edges[6] = {{4, 0}, {7, 0}, {8, 0}};
    edges[7] = {{3, 0}, {6, 0}};
    edges[8] = {{4, 0}, {5, 0}, {6, 0}};

    for (auto &i : edges)
        for (auto &j : i.second)
            G.add_edge(Edge<T>{i.first, j.first, j.second});

    return G;
}

#endif