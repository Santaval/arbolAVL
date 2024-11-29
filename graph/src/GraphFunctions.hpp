#ifndef GRAPH_FUNCTIONS_HPP
#define GRAPH_FUNCTIONS_HPP

#include "Graph.hpp"
#include <vector>
#include <limits>

/**
 * @brief Clase que proporciona funcionalidades adicionales para grafos.
 */
class GraphFunctions {
public:
    /**
     * @brief Cuenta el número de aristas en el grafo.
     * 
     * Requiere: `graph` es un grafo válido.
     * Modifica: Ninguna.
     * Efecto: Devuelve el número total de aristas en el grafo.
     */
    static int count_edges(Graph& graph);

    /**
     * @brief Cuenta el número de vértices adyacentes a un vértice dado.
     * 
     * Requiere: `graph` es un grafo válido, `v` es un vértice en el grafo.
     * Modifica: Ninguna.
     * Efecto: Devuelve el número de vértices adyacentes al vértice `v`.
     */
    static int count_adjacent_vertices(Graph& graph, Vertex v);

    /**
     * @brief Determina si el grafo está conectado utilizando DFS.
     * 
     * Requiere: `graph` es un grafo válido.
     * Modifica: Ninguna.
     * Efecto: Devuelve true si el grafo está conectado; false en caso contrario.
     */
    static bool is_connected_dfs(Graph& graph);

    /**
     * @brief Determina si el grafo está conectado utilizando BFS.
     * 
     * Requiere: `graph` es un grafo válido.
     * Modifica: Ninguna.
     * Efecto: Devuelve true si el grafo está conectado; false en caso contrario.
     */
    static bool is_connected_bfs(Graph& graph);

    /**
     * @brief Calcula las distancias más cortas desde un vértice fuente utilizando el algoritmo de Dijkstra.
     * 
     * Requiere: `graph` es un grafo válido, `distances` es un arreglo de tamaño suficiente para almacenar las distancias.
     * Modifica: `distances`.
     * Efecto: Actualiza `distances` con las distancias mínimas desde el vértice `source` al resto de los vértices.
     */
    static void dijkstra(Graph& graph, Vertex source, double* distances);

    /**
     * @brief Calcula las distancias más cortas entre todos los pares de vértices utilizando Floyd-Warshall.
     * 
     * Requiere: `graph` es un grafo válido, `distances` es una matriz cuadrada de tamaño igual al número de vértices.
     * Modifica: `distances`.
     * Efecto: Actualiza `distances` con las distancias mínimas entre todos los pares de vértices.
     */
    static void floyd_warshall(Graph& graph, double** distances);

    /**
     * @brief Calcula las distancias más cortas entre todos los pares de vértices utilizando Dijkstra repetidamente.
     * 
     * Requiere: `graph` es un grafo válido, `distances` es una matriz cuadrada de tamaño igual al número de vértices.
     * Modifica: `distances`.
     * Efecto: Actualiza `distances` con las distancias mínimas entre todos los pares de vértices.
     */
    static void all_pairs_dijkstra(Graph& graph, double** distances);

    /**
     * @brief Encuentra el árbol de expansión mínima utilizando el algoritmo de Prim.
     * 
     * Requiere: `graph` es un grafo válido, `parent` es un arreglo con tamaño suficiente para almacenar los padres.
     * Modifica: `parent`.
     * Efecto: Llena `parent` para representar el árbol de expansión mínima.
     */
    static void prim(Graph& graph, int* parent);

    /**
     * @brief Representa los detalles de una arista para algoritmos como Kruskal.
     */
    struct EdgeDetail {
        int u, v;
        double weight;
    };

    /**
     * @brief Encuentra el árbol de expansión mínima utilizando el algoritmo de Kruskal.
     * 
     * Requiere: `graph` es un grafo válido.
     * Modifica: `mst`.
     * Efecto: Llena `mst` con las aristas que forman el árbol de expansión mínima.
     */
    static void kruskal(Graph& graph, std::vector<EdgeDetail>& mst);

    /**
     * @brief Calcula un camino hamiltoniano de costo mínimo en el grafo.
     * 
     * Requiere: `graph` es un grafo válido.
     * Modifica: `best_path`.
     * Efecto: Llena `best_path` con la secuencia de vértices que forman el camino hamiltoniano de menor costo.
     * Devuelve el costo del camino.
     */
    static double hamiltonian_path(Graph& graph, std::vector<int>& best_path);
};

#endif // GRAPH_FUNCTIONS_HPP
