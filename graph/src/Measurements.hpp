#ifndef MEASUREMENTS_HPP
#define MEASUREMENTS_HPP

#include <chrono>
#include <string>
#include <fstream>
#include "ListGraph.hpp"
#include "GraphFunctions.hpp"

class Measurements {
public:
    // Constructor y destructor
    Measurements(const std::string& output_file);
    ~Measurements();

    // Medir y registrar el tiempo de un algoritmo
    void run_measurement(const std::string& algorithm_name, const ListGraph& graph);

    // Generar un grafo aleatorio
    static ListGraph generate_random_graph(size_t vertices, double density);

private:
    std::ofstream output; // Archivo para guardar resultados

    // Función genérica para medir el tiempo de una función
    template <typename Func>
    double measure_time(Func func);
};

#endif // MEASUREMENTS_HPP

