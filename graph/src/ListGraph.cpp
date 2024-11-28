#include <iostream>
#include "ListGraph.hpp"

// AdjacencyList methods
void AdjacencyList::add_edge(Vertex v, double weight) {
    // Verificar si ya existe una arista hacia el vértice 'v'
    for (size_t i = 0; i < edge_count; ++i) {
        if (edges[i].vertex.number == v.number) {
            return; // Arista ya existe, no hacer nada
        }
    }

    // Asegurarnos de que haya espacio para la nueva arista
    if (edge_capacity == 0) {
        edge_capacity = 2;
        edges = new Edge[edge_capacity];
    } else if (edge_count >= edge_capacity) {
        edge_capacity *= 2;
        Edge* new_edges = new Edge[edge_capacity];
        for (size_t i = 0; i < edge_count; ++i) {
            new_edges[i] = edges[i];
        }
        delete[] edges;
        edges = new_edges;
    }

    // Agregar la nueva arista
    edges[edge_count++] = Edge(v, weight);
}

void AdjacencyList::remove_edge(Vertex v) {
    for (size_t i = 0; i < edge_count; ++i) {
        if (edges[i].vertex.number == v.number) {
            for (size_t j = i; j < edge_count - 1; ++j) {
                edges[j] = edges[j + 1];
            }
            --edge_count;
            break;
        }
    }
}

// ListGraph methods
ListGraph::ListGraph() : adjacencyLists(nullptr), elements(nullptr), vertex_capacity(0), Graph() {}

ListGraph::~ListGraph() {
    clear();
}

void ListGraph::clear() {
    for (size_t i = 0; i < vertex_count; ++i) {
        delete[] adjacencyLists[i].edges;
    }
    delete[] adjacencyLists;
    delete[] elements;

    adjacencyLists = nullptr;
    elements = nullptr;
    vertex_count = 0;
    vertex_capacity = 0;
}

void ListGraph::ensure_vertex_capacity() {
    if (vertex_capacity == 0) {
        vertex_capacity = 2;
        adjacencyLists = new AdjacencyList[vertex_capacity];
        elements = new char[vertex_capacity];
    } else if (vertex_count >= vertex_capacity) {
        vertex_capacity *= 2;

        // Crear nuevos arrays
        AdjacencyList* new_lists = new AdjacencyList[vertex_capacity];
        char* new_elements = new char[vertex_capacity];

        // Copiar datos manualmente
        for (size_t i = 0; i < vertex_count; ++i) {
            new_lists[i] = adjacencyLists[i];
            new_elements[i] = elements[i];
        }

        // Liberar memoria antigua
        delete[] adjacencyLists;
        delete[] elements;

        adjacencyLists = new_lists;
        elements = new_elements;
    }
}

void ListGraph::append_vertex(char element) {
    ensure_vertex_capacity();

    Vertex v(vertex_count);
    elements[vertex_count] = element;
    adjacencyLists[vertex_count] = AdjacencyList();
    adjacencyLists[vertex_count].vertex = v;

    this->vertex_count++;
}

void ListGraph::delete_vertex(Vertex vertex) {
    size_t index = vertex.number;

    delete[] adjacencyLists[index].edges;

    for (size_t i = index; i < vertex_count - 1; ++i) {
        adjacencyLists[i] = adjacencyLists[i + 1];
        elements[i] = elements[i + 1];
    }

    this->vertex_count--;

    for (size_t i = 0; i < vertex_count; ++i) {
        adjacencyLists[i].remove_edge(vertex);

        update_edges_after_vertex_removal(adjacencyLists[i], index);
    }
}

void ListGraph::update_edges_after_vertex_removal(AdjacencyList& adjacencyList, size_t removed_index) {
    for (size_t i = 0; i < adjacencyList.edge_count; ++i) {
        if (adjacencyList.edges[i].vertex.number > (int)removed_index) {
            --adjacencyList.edges[i].vertex.number;
        }
    }
}



void ListGraph::modify_element(Vertex vertex, char new_element) {
    if (vertex.number < (int)vertex_count) {
        elements[vertex.number] = new_element;
    }
}

char ListGraph::element(Vertex vertex) {
    if (vertex.number < (int)vertex_count) {
        return elements[vertex.number];
    }
    return '\0';
}

void ListGraph::add_edge(Vertex v1, Vertex v2, double weight) {
    // Los vertices no existen y el peso es invalido
    if (v1.number >= (int)vertex_count || v2.number >= (int)vertex_count || weight <= 0) {
        return;
    }

    // No aristas paralelas
    if (v1.number == v2.number) {
        return; // No se permiten lazos
    }

    adjacencyLists[v1.number].add_edge(v2, weight);
    adjacencyLists[v2.number].add_edge(v1, weight);
}

void ListGraph::delete_edge(Vertex v1, Vertex v2) {
    adjacencyLists[v1.number].remove_edge(v2);
    adjacencyLists[v2.number].remove_edge(v1);
}

void ListGraph::modify_weight(Vertex v1, Vertex v2, double new_weight) {
    bool found_v1_to_v2 = false;
    bool found_v2_to_v1 = false;

    // Modificar peso en la dirección v1 -> v2 si la arista existe
    for (size_t i = 0; i < adjacencyLists[v1.number].edge_count; ++i) {
        if (adjacencyLists[v1.number].edges[i].vertex.number == v2.number) {
            adjacencyLists[v1.number].edges[i].weight = new_weight;
            found_v1_to_v2 = true;
            break;
        }
    }

    // Modificar peso en la dirección v2 -> v1 si la arista existe
    for (size_t i = 0; i < adjacencyLists[v2.number].edge_count; ++i) {
        if (adjacencyLists[v2.number].edges[i].vertex.number == v1.number) {
            adjacencyLists[v2.number].edges[i].weight = new_weight;
            found_v2_to_v1 = true;
            break;
        }
    }

    // Si alguna arista no fue encontrada
    if (!found_v1_to_v2 || !found_v2_to_v1) {
        std::cout << "Una o ambas aristas no existen entre los vértices " <<
                v1.number << "-" << v2.number << std::endl;
    }
}


double ListGraph::weight(Vertex v1, Vertex v2) {
    for (size_t i = 0; i < adjacencyLists[v1.number].edge_count; ++i) {
        if (adjacencyLists[v1.number].edges[i].vertex.number == v2.number) {
            return adjacencyLists[v1.number].edges[i].weight;
        }
    }
    return -1;
}

Vertex ListGraph::first_vertex() {
    return vertex_count > 0 ? adjacencyLists[0].vertex : Vertex(-1);
}

Vertex ListGraph::next_vertex(Vertex vertex) {
    return vertex.number + 1 < (int)vertex_count ? adjacencyLists[vertex.number + 1].vertex : Vertex(-1);
}

Vertex ListGraph::first_adyacent_vertex(Vertex vertex) {
    return adjacencyLists[vertex.number].edge_count > 0 ? adjacencyLists[vertex.number].edges[0].vertex : Vertex(-1);
}

Vertex ListGraph::next_adyacent_vertex(Vertex vertex, Vertex adj_vertex) {
    const auto& list = adjacencyLists[vertex.number];
    for (size_t i = 0; i < list.edge_count; ++i) {
        if (list.edges[i].vertex.number == adj_vertex.number && i + 1 < list.edge_count) {
            return list.edges[i + 1].vertex;
        }
    }
    return Vertex(-1);
}
