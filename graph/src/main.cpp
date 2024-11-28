#include <iostream>
#include <vector>
#include <string>

#include "Measurements.hpp"
#include "Graph.hpp"
#include "ListGraph.hpp"

int main() {
    // Crear el archivo de mediciones
    Measurements measurements("measurements.csv");

    // Algoritmos que se van a medir
    std::vector<std::string> algorithms = {
        "Count Edges",
        "Count Adjacent Vertices",
        "Is Connected (DFS)",
        "Is Connected (BFS)",
        "Dijkstra",
        "Floyd-Warshall",
        "All Pairs Dijkstra",
        "Prim",
        "Kruskal",
        "Hamiltonian Path"
    };

    std::vector<size_t> vertex_sizes = {10};
    std::vector<double> densities = {0.9};

    // Generar grafos y medir
    for (const auto& vertices : vertex_sizes) {
        for (const auto& density : densities) {
            Graph* graph = new ListGraph();
            measurements.generate_random_graph(graph, vertices, density);
            for (const auto& algorithm : algorithms) {
                std::cout << "Measuring " << algorithm << " for "
                    << vertices<< " vertices, density " << density << "...\n";
                measurements.run_measurement(algorithm, graph);
            }
        }
    }

    std::cout << "Mediciones completadas. Resultados guardados en measurements.csv\n";
    return 0;
}