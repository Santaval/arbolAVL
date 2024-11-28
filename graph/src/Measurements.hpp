#ifndef MEASUREMENTS_HPP
#define MEASUREMENTS_HPP

#include <chrono>
#include <string>
#include <fstream>
#include "Graph.hpp" // Clase base abstracta para ListGraph y MatrixGraph
#include "GraphFunctions.hpp" // Funciones independientes que trabajan con Graph

class Measurements {
public:
    Measurements(const std::string& output_file);
    ~Measurements();

    // Medir y registrar el tiempo de un algoritmo
    void run_measurement(const std::string& algorithm_name, Graph* graph);

    // Generar un grafo aleatorio
    static Graph* generate_random_graph(Graph* graph, size_t vertices, double density);

private:
    std::ofstream output; // Archivo para guardar resultados

    // Función genérica para medir el tiempo de una función
    template <typename Func>
    double measure_time(Func func);
};

#endif // MEASUREMENTS_HPP
