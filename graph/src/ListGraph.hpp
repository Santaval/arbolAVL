#ifndef LIST_GRAPH_HPP
#define LIST_GRAPH_HPP

#include <cstddef>

class Vertex {
public:
    int id;
    Vertex() : id(-1) {}
    Vertex(int id) : id(id) {}
};

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

    ~AdjacencyList() {
        delete[] edges;
    }

    void add_edge(Vertex v, double weight);
    void remove_edge(Vertex v);
};

class ListGraph {
// Por facilidad para que las funciones que trabajan sobre el grafo
// puedan hacerlo con más facilidad
public:
    AdjacencyList* adjacencyLists;
    char* elements;
    size_t vertex_count;
    size_t vertex_capacity;

    void ensure_vertex_capacity();
    void ensure_edge_capacity(AdjacencyList& list);

public:
    ListGraph();
    ~ListGraph();

    void clear();
    void append_vertex(char element);
    void delete_vertex(Vertex vertex);
    void modify_element(Vertex vertex, char new_element);
    char element(Vertex vertex) const;

    void add_edge(Vertex v1, Vertex v2, double weight);
    void delete_edge(Vertex v1, Vertex v2);
    void modify_weight(Vertex v1, Vertex v2, double new_weight);
    double weight(Vertex v1, Vertex v2) const;

    Vertex first_vertex() const;
    Vertex next_vertex(Vertex vertex) const;
    Vertex first_adjacent_vertex(Vertex vertex) const;
    Vertex next_adjacent_vertex(Vertex vertex, Vertex adj_vertex) const;
};

#endif // LIST_GRAPH_HPP


