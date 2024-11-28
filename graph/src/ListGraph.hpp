#ifndef LIST_GRAPH_HPP
#define LIST_GRAPH_HPP

#include <cstddef>
#include "Vertex.hpp"
#include "Graph.hpp"

class Edge {
public:
    Vertex vertex;
    double weight;
    Edge() : vertex(Vertex()), weight(0.0) {}
    Edge(Vertex v, double w) : vertex(v), weight(w) {}
};

class AdjacencyList {
public:
    Vertex vertex;
    Edge* edges;
    size_t edge_count;
    size_t edge_capacity;

    AdjacencyList() : vertex(Vertex()), edges(nullptr), edge_count(0), edge_capacity(0) {}

    void add_edge(Vertex v, double weight);
    void remove_edge(Vertex v);
};

class ListGraph : public Graph {
// Por facilidad para que las funciones que trabajan sobre el grafo
// puedan hacerlo con más facilidad
public:
    AdjacencyList* adjacencyLists;
    char* elements;
    size_t vertex_capacity;

    void ensure_vertex_capacity();
    void ensure_edge_capacity(AdjacencyList& list);

public:
    ListGraph();
    ~ListGraph();

    void clear() override;
    void append_vertex(char element) override;
    void delete_vertex(Vertex vertex) override;
    void modify_element(Vertex vertex, char new_element) override;
    char element(Vertex vertex) override;

    void add_edge(Vertex v1, Vertex v2, double weight) override;
    void delete_edge(Vertex v1, Vertex v2) override;
    void modify_weight(Vertex v1, Vertex v2, double new_weight) override;
    double weight(Vertex v1, Vertex v2) override;
    void update_edges_after_vertex_removal(AdjacencyList& adjacencyList, size_t removed_index);

    Vertex first_vertex() override;
    Vertex next_vertex(Vertex vertex) override;
    Vertex first_adyacent_vertex(Vertex vertex) override;
    Vertex next_adyacent_vertex(Vertex vertex, Vertex adj_vertex) override;
};

#endif // LIST_GRAPH_HPP


