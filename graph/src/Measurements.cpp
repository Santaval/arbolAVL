#include "Measurements.hpp"
#include <random>
#include <iostream>

// Constructor: inicializa el archivo de salida
Measurements::Measurements(const std::string& output_file) {
    output.open(output_file);
    if (!output.is_open()) {
        throw std::runtime_error("Error al abrir el archivo de salida: " + output_file);
    }
    output << "Algorithm,Vertices,Density,Time(ms)\n";
}

// Destructor: cierra el archivo de salida
Measurements::~Measurements() {
    if (output.is_open()) {
        output.close();
    }
}

// Función genérica para medir el tiempo
template <typename Func>
double Measurements::measure_time(Func func) {
    auto start = std::chrono::high_resolution_clock::now();
    func();
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double, std::milli>(end - start).count();
}

// Generar un grafo aleatorio
Graph* Measurements::generate_random_graph(Graph* graph, size_t vertices, double density) {
    // Agregar vértices
    for (size_t i = 0; i < vertices; ++i) {
        graph->append_vertex('A' + (i % 26)); // Etiquetas cíclicas A-Z
    }

    // Generador aleatorio para las aristas
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> weight_dist(1.0, 10.0); // Pesos entre 1 y 10
    std::uniform_real_distribution<> prob_dist(0.0, 1.0);    // Probabilidad de arista

    for (size_t i = 0; i < vertices; ++i) {
        for (size_t j = i + 1; j < vertices; ++j) {
            if (prob_dist(gen) < density) { // Agregar arista con probabilidad = densidad
                graph->add_edge(Vertex(i), Vertex(j), weight_dist(gen));
            }
        }
    }

    return graph;
}

// Ejecutar y registrar la medición de un algoritmo
void Measurements::run_measurement(const std::string& algorithm_name, Graph* graph) {
    size_t vertices = graph->vertex_count;
    double density = 0.0;
    int edge_count = GraphFunctions::count_edges(*graph);
    density = static_cast<double>(edge_count) / (vertices * (vertices - 1) / 2);

    if (algorithm_name == "Dijkstra") {
        double* distances = new double[vertices];
        double duration = measure_time([&]() {
            GraphFunctions::dijkstra(*graph, Vertex(0), distances);
        });
        delete[] distances;
        output << "Dijkstra," << vertices << "," << density << "," << duration << "\n";

    } else if (algorithm_name == "Floyd-Warshall") {
        double** distances = new double*[vertices];
        for (size_t i = 0; i < vertices; ++i) {
            distances[i] = new double[vertices];
        }
        double duration = measure_time([&]() {
            GraphFunctions::floyd_warshall(*graph, distances);
        });
        for (size_t i = 0; i < vertices; ++i) {
            delete[] distances[i];
        }
        delete[] distances;
        output << "Floyd-Warshall," << vertices << "," << density << "," << duration << "\n";

    } else if (algorithm_name == "All Pairs Dijkstra") {
        double** distances = new double*[vertices];
        for (size_t i = 0; i < vertices; ++i) {
            distances[i] = new double[vertices];
        }
        double duration = measure_time([&]() {
            GraphFunctions::all_pairs_dijkstra(*graph, distances);
        });
        for (size_t i = 0; i < vertices; ++i) {
            delete[] distances[i];
        }
        delete[] distances;
        output << "All Pairs Dijkstra," << vertices << "," << density << "," << duration << "\n";

    } else if (algorithm_name == "Prim") {
        int* parent = new int[vertices];
        double duration = measure_time([&]() {
            GraphFunctions::prim(*graph, parent);
        });
        delete[] parent;
        output << "Prim," << vertices << "," << density << "," << duration << "\n";

    } else if (algorithm_name == "Kruskal") {
        std::vector<GraphFunctions::EdgeDetail> mst;
        double duration = measure_time([&]() {
            GraphFunctions::kruskal(*graph, mst);
        });
        output << "Kruskal," << vertices << "," << density << "," << duration << "\n";

    } else if (algorithm_name == "Hamiltonian Path") {
        std::vector<int> best_path;
        double duration = measure_time([&]() {
            GraphFunctions::hamiltonian_path(*graph, best_path);
        });
        output << "Hamiltonian Path," << vertices << "," << density << "," << duration << "\n";

    } else if (algorithm_name == "Is Connected (DFS)") {
        double duration = measure_time([&]() {
            GraphFunctions::is_connected_dfs(*graph);
        });
        output << "Is Connected (DFS)," << vertices << "," << density << "," << duration << "\n";

    } else if (algorithm_name == "Is Connected (BFS)") {
        double duration = measure_time([&]() {
            GraphFunctions::is_connected_bfs(*graph);
        });
        output << "Is Connected (BFS)," << vertices << "," << density << "," << duration << "\n";

    } else if (algorithm_name == "Count Edges") {
        double duration = measure_time([&]() {
            GraphFunctions::count_edges(*graph);
        });
        output << "Count Edges," << vertices << "," << density << "," << duration << "\n";

    } else if (algorithm_name == "Count Adjacent Vertices") {
        Vertex test_vertex(0);
        double duration = measure_time([&]() {
            GraphFunctions::count_adjacent_vertices(*graph, test_vertex);
        });
        output << "Count Adjacent Vertices," << vertices << "," << density << "," << duration << "\n";
    }
}
