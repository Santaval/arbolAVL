#ifndef GRAPH_FUNCTIONS_HPP
#define GRAPH_FUNCTIONS_HPP

#include "Vertex.hpp"
#include "ListGraph.hpp"
#include <vector>

// Clase para implementar funciones sobre grafos
class GraphFunctions {
public:
    // 1. Contar aristas en el grafo
    static int count_edges(const ListGraph& graph);

    // 2. Contar vértices adyacentes de un vértice dado
    static int count_adjacent_vertices(const ListGraph& graph, Vertex v);

    // 3. Verificar si un grafo es conexo usando DFS
    static bool is_connected_dfs(const ListGraph& graph);

    // 4. Verificar si un grafo es conexo usando BFS
    static bool is_connected_bfs(const ListGraph& graph);

    // 5. Algoritmo de Dijkstra
    static void dijkstra(const ListGraph& graph, Vertex source, double* distances);

    // 6. Algoritmo de Floyd-Warshall
    static void floyd_warshall(const ListGraph& graph, double** distances);

    // 7. Caminos más cortos entre pares de vértices usando Dijkstra
    static void all_pairs_dijkstra(const ListGraph& graph, double** distances);

    // 8. Algoritmo de Prim para árbol de expansión mínima
    static void prim(const ListGraph& graph, int* parent);

    // 9. Algoritmo de Kruskal para árbol de expansión mínima
    struct EdgeDetail {
        int u, v;
        double weight;
    };
    static void kruskal(const ListGraph& graph, std::vector<EdgeDetail>& mst);

    // 10. Circuito Hamilton de menor costo (búsqueda exhaustiva)
    static double hamiltonian_path(const ListGraph& graph, std::vector<int>& best_path);
};

#endif // GRAPH_FUNCTIONS_HPP
