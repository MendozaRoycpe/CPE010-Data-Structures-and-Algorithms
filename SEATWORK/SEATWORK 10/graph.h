//
// Created by royga on 9/29/2026.
//

#ifndef UNTITLED1_GRAPH_H
#define UNTITLED1_GRAPH_H

#include <iostream>
#include <vector>
#include <map>

/**
 * @brief Represents an individual node (Vertex) in the graph.
 */
class Vertex {
private:

public:
    int id; // Unique identifier for the vertex

    // Adjacency map: maps neighboring vertex ID -> edge weight
    std::map<int, int> connectedTo;

    // Default constructor
    Vertex(){}

    // Parameterized constructor to initialize vertex with a specific key/ID
    Vertex(int key) {
        id = key;
    }

    // Adds a directed edge/neighbor to this vertex with an optional weight (default 0)
    void addNeig(int nbr, int weight=0) {
        connectedTo[nbr] = weight;
    }

    // Returns a vector containing the IDs of all connected neighbor vertices
    std::vector<int> getCons() {
        std::vector<int> keys;
        // Iteration to find and store all neighbor keys from the map
        for (std::map<int, int>::iterator it = connectedTo.begin(); it != connectedTo.end(); it++) {
            keys.push_back(it->first);
        }
        return keys;
    }

    // Returns the vertex ID
    int getId() {
        return id;
    }

    // Returns the edge weight connecting this vertex to a given neighbor
    int getWeight(int nbr) {
        return connectedTo[nbr];
    }

    // Friend declaration for stream insertion operator overloading to print vertex details
    friend std::ostream &operator<<(std::ostream &, Vertex &);
};

/**
 * @brief Overloads the << operator for Vertex objects to display all its outgoing edges and weights.
 */
inline std::ostream &operator<<(std::ostream &stream, Vertex &vert) {
    std::vector<int> connects = vert.getCons();
    for (unsigned int i = 0; i < connects.size(); i++) {
        stream << "( " << vert.id << " , " << connects[i] << " ) weight: " << vert.getWeight(connects[i]) << "\n";
    }

    return stream;
}

/**
 * @brief Represents the overall Graph structure containing multiple vertices and edges.
 */
class Graph {
public:
    // Master list mapping vertex ID to its corresponding Vertex object
    std::map<int, Vertex> vertList;
    int numVertices; // Total count of vertices in the graph

    // Constructor initializes an empty graph with 0 vertices
    Graph() {
        numVertices = 0;
    }

    // Creates and adds a new vertex with the specified key to the graph
    Vertex addVertex(int key) {
        numVertices++;
        Vertex newVertex = Vertex(key);
        this->vertList[key] = newVertex;
        return newVertex;
    }

    // Retrieves a pointer to a vertex by its key (returns nullptr if not found)
    Vertex *getVertex(int n) {
        for (std::map<int, Vertex>::iterator it = vertList.begin(); it != vertList.end(); ++it) {
            if (it->first == n) {
                Vertex *vpntr = &vertList[n];
                return vpntr;
            } else {
                return nullptr;
            }
        }
        return nullptr;
    }

    // Checks if a vertex with key 'n' exists in the graph
    bool contains(int n) {
        for (std::map<int, Vertex>::iterator it = vertList.begin(); it != vertList.end(); ++it) {
            if (it->first == n) {
                return true;
            }
        }
        return false;
    }

    // Adds a directed, weighted edge from vertex 'f' to vertex 't'
    void addEdge(int f, int t, int cost = 0) {
        // If the source vertex doesn't exist, automatically create it
        if (!this->contains(f)) {
            std::cout << f << " was not found, adding!" << std::endl;
            this->addVertex(f);
        }
        // If the destination vertex doesn't exist, notify (note: destination vertex creation should ideally be added here too)
        if (!this->contains(t)) {
            std::cout << t << " was not found, adding!" << std::endl;
        }
        // Establish connection in the source vertex's adjacency map
        vertList[f].addNeig(t, cost);
    }

    // Returns a vector containing all vertex IDs present in the graph
    std::vector<int> getVertices() {
        std::vector<int> verts;

        for (std::map<int, Vertex>::iterator it = vertList.begin(); it != vertList.end(); ++it) {
            verts.push_back(it->first);
        }
        return verts;
    }

    // Friend declaration for stream insertion operator overloading to print the entire graph
    friend std::ostream &operator<<(std::ostream &, Graph &);
};

/**
 * @brief Overloads the << operator for Graph objects to iterate and print all vertex adjacency lists.
 */
inline std::ostream &operator<<(std::ostream &stream, Graph &grph) {
    for (std::map<int, Vertex>::iterator it = grph.vertList.begin(); it != grph.vertList.end(); ++it) {
        stream << it->second;
    }

    return stream;
}

#endif //UNTITLED1_GRAPH_H