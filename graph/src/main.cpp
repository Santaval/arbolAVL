#include <iostream>
#include "ListGraph.hpp"
#include "GraphFunctions.hpp"

int main() {
    // Crear un grafo con algunos vértices
    ListGraph graph;
    graph.append_vertex('A');
    graph.append_vertex('B');
    graph.append_vertex('C');
    graph.append_vertex('D');

    graph.add_edge(Vertex(0), Vertex(1), 10.0);
    graph.add_edge(Vertex(0), Vertex(2), 15.0);
    graph.add_edge(Vertex(1), Vertex(2), 35.0);
    graph.add_edge(Vertex(1), Vertex(3), 25.0);
    graph.add_edge(Vertex(2), Vertex(3), 30.0);

    // Kruskal
    std::vector<GraphFunctions::EdgeDetail> mst;
    GraphFunctions::kruskal(graph, mst);
    std::cout << "MST (Kruskal):" << std::endl;
    for (const auto& edge : mst) {
        std::cout << edge.u << " -- " << edge.v << " : " << edge.weight << std::endl;
    }

    // Hamilton
    std::vector<int> best_path;
    double min_cost = GraphFunctions::hamiltonian_path(graph, best_path);
    std::cout << "Circuito Hamilton de menor costo: " << min_cost << std::endl;
    std::cout << "Ruta: ";
    for (int v : best_path) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    return 0;
}
