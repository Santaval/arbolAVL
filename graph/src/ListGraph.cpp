#include "ListGraph.hpp"
#include <iostream>
#include <algorithm>

void ListGraph::clear() {
    this->adjacencyList.clear();
    this->elements.clear();
    this->size = 0;
}

void ListGraph::append_vertex(char element) {
    Vertex newVertex(this->elements.size());
    this->elements.push_back(element);
    this->adjacencyList[newVertex] = {};
    this->size++;
}

void ListGraph::delete_vertex(Vertex vertex) {
    // Eliminar el vértice de la lista de adyacencia
    this->adjacencyList.erase(vertex);

    // Eliminar el vértice de las listas de adyacencia de otros vértices
    for (auto& [key, adjList] : this->adjacencyList) {
        adjList.erase(std::remove_if(adjList.begin(), adjList.end(),
                                     [vertex](const auto& edge) {
                                         return edge.first == vertex;
                                     }),
                      adjList.end());
    }

    // Actualizar el vector de elementos
    this->elements.erase(this->elements.begin() + vertex);

    // Actualizar índices en la lista de adyacencia
    std::unordered_map<Vertex, std::vector<std::pair<Vertex, double>>> newAdjList;
    int index = 0;
    for (const auto& [key, adjList] : this->adjacencyList) {
        newAdjList[Vertex(index)] = adjList;
        ++index;
    }
    this->adjacencyList = newAdjList;
    this->size--;
}

void ListGraph::modify_element(Vertex vertex, char newElement) {
    this->elements[vertex] = newElement;
}

char ListGraph::element(Vertex vertex) {
    return this->elements[vertex];
}

void ListGraph::add_edge(Vertex vertex1, Vertex vertex2, double weight) {
    if (weight <= 0 || vertex1 == vertex2) return;

    this->adjacencyList[vertex1].emplace_back(vertex2, weight);
    this->adjacencyList[vertex2].emplace_back(vertex1, weight); // No dirigido
}

void ListGraph::delete_edge(Vertex vertex1, Vertex vertex2) {
    auto& adjList1 = this->adjacencyList[vertex1];
    adjList1.erase(std::remove_if(adjList1.begin(), adjList1.end(),
                                  [vertex2](const auto& edge) {
                                      return edge.first == vertex2;
                                 }),
                   adjList1.end());

    auto& adjList2 = this->adjacencyList[vertex2];
    adjList2.erase(std::remove_if(adjList2.begin(), adjList2.end(),
                                  [vertex1](const auto& edge) {
                                      return edge.first == vertex1;
                                  }),
                   adjList2.end());
}

void ListGraph::modify_weight(Vertex vertex1, Vertex vertex2, double newWeight) {
    for (auto& edge : this->adjacencyList[vertex1]) {
        if (edge.first == vertex2) {
            edge.second = newWeight;
            break;
        }
    }

    for (auto& edge : this->adjacencyList[vertex2]) {
        if (edge.first == vertex1) {
            edge.second = newWeight;
            break;
        }
    }
}

double ListGraph::weight(Vertex vertex1, Vertex vertex2) {
    for (const auto& edge : this->adjacencyList[vertex1]) {
        if (edge.first == vertex2) {
            return edge.second;
        }
    }
    return -1; // Arista no existe
}

Vertex ListGraph::first_vertex() {
    if (this->adjacencyList.empty()) {
        return Vertex();
    }
    return Vertex(0);
}

Vertex ListGraph::next_vertex(Vertex vertex) {
    if (vertex + 1 < this->elements.size()) {
        return Vertex(vertex + 1);
    }
    return Vertex(); // Vértice nulo
}

Vertex ListGraph::first_adjacent(Vertex vertex) {
    if (!this->adjacencyList[vertex].empty()) {
        return this->adjacencyList[vertex].front().first;
    }
    return Vertex(); // Sin adyacentes
}

Vertex ListGraph::next_adjacent(Vertex vertex, Vertex adjacent) {
    const auto& adjList = this->adjacencyList[vertex];
    for (size_t i = 0; i < adjList.size(); ++i) {
        if (adjList[i].first == adjacent && i + 1 < adjList.size()) {
            return adjList[i + 1].first;
        }
    }
    return Vertex(); // No hay más adyacentes
}

void ListGraph::print_graph() {
    for (const auto& [vertex, edges] : this->adjacencyList) {
        std::cout << "Vertex " << vertex << ": ";
        for (const auto& [adjVertex, weight] : edges) {
            std::cout << "(" << adjVertex << ", " << weight << ") ";
        }
        std::cout << "\n";
    }
}
