#ifndef GRAPH_FUNCTIONS_HPP
#define GRAPH_FUNCTIONS_HPP

#include "Graph.hpp"
#include <vector>
#include <limits>

class GraphFunctions {
public:
    static int count_edges(Graph& graph);
    static int count_adjacent_vertices(Graph& graph, Vertex v);
    static bool is_connected_dfs(Graph& graph);
    static bool is_connected_bfs(Graph& graph);
    static void dijkstra(Graph& graph, Vertex source, double* distances);
    static void floyd_warshall(Graph& graph, double** distances);
    static void all_pairs_dijkstra(Graph& graph, double** distances);
    static void prim(Graph& graph, int* parent);

    struct EdgeDetail {
    int u, v;
    double weight;
    };
    static void kruskal(Graph& graph, std::vector<EdgeDetail>& mst);
    static double hamiltonian_path(Graph& graph, std::vector<int>& best_path);
};

#endif // GRAPH_FUNCTIONS_HPP
