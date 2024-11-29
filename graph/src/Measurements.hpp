#ifndef MEASUREMENTS_HPP
#define MEASUREMENTS_HPP

#include <chrono>
#include <string>
#include <fstream>
#include "Graph.hpp"          // Clase base abstracta para ListGraph y MatrixGraph
#include "GraphFunctions.hpp" // Funciones independientes que trabajan con Graph

/**
 * @class Measurements
 * @brief Clase para realizar mediciones de tiempo en algoritmos aplicados a grafos.
 *
 * La clase permite medir el tiempo de ejecución de algoritmos específicos, generar grafos aleatorios,
 * y registrar los resultados en un archivo de salida.
 */
class Measurements {
public:
    /**
     * @brief Constructor de la clase Measurements.
     *
     * @param output_file Nombre del archivo donde se guardarán los resultados de las mediciones.
     * @requires El nombre del archivo debe ser válido y accesible para escritura.
     * @modifica Crea y abre el archivo de salida para registrar resultados.
     * @efecto Inicializa un objeto Measurements con un archivo de salida abierto.
     */
    Measurements(const std::string& output_file);

    /**
     * @brief Destructor de la clase Measurements.
     *
     * @requires El archivo de salida debe haber sido correctamente inicializado.
     * @modifica Cierra el archivo de salida si está abierto.
     * @efecto Libera los recursos asociados con el archivo de salida.
     */
    ~Measurements();

    /**
     * @brief Ejecuta y mide el tiempo de un algoritmo aplicado a un grafo.
     *
     * @param algorithm_name Nombre del algoritmo que se está midiendo.
     * @param graph Puntero al grafo sobre el cual se ejecutará el algoritmo.
     * @requires El grafo debe estar correctamente inicializado y ser válido.
     * @modifica Registra los resultados de la medición en el archivo de salida.
     * @efecto Calcula y guarda el tiempo de ejecución del algoritmo aplicado al grafo.
     */
    void run_measurement(const std::string& algorithm_name, Graph* graph);

    /**
     * @brief Genera un grafo aleatorio con un número especificado de vértices y densidad.
     *
     * @param graph Puntero a un grafo que será modificado para contener los datos generados.
     * @param vertices Número de vértices del grafo.
     * @param density Densidad del grafo (valor entre 0 y 1, donde 1 indica grafo completo).
     * @requires El puntero del grafo debe ser válido y el número de vértices mayor que cero.
     * @modifica Crea un nuevo grafo con las especificaciones proporcionadas.
     * @efecto Devuelve un grafo aleatorio generado según los parámetros dados.
     */
    static Graph* generate_random_graph(Graph* graph, size_t vertices, double density);

private:
    std::ofstream output; /**< Archivo para guardar los resultados de las mediciones. */

    /**
     * @brief Función genérica para medir el tiempo de una función.
     *
     * @tparam Func Tipo de la función a medir.
     * @param func La función que se va a ejecutar y medir.
     * @requires La función debe ser válida y ejecutable en el contexto actual.
     * @modifica Ningún estado externo; solo mide el tiempo de ejecución.
     * @efecto Calcula el tiempo de ejecución de la función dada y devuelve su duración en milisegundos.
     * @return Duración en milisegundos como un valor de tipo `double`.
     */
    template <typename Func>
    double measure_time(Func func);
};

#endif // MEASUREMENTS_HPP
