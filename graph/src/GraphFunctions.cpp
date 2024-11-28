#include "GraphFunctions.hpp"
#include <queue>
#include <algorithm>
#include <limits>

// 1. Contar aristas en el grafo
int GraphFunctions::count_edges(ListGraph& graph) {
    int edge_count = 0;
    for (Vertex v = graph.first_vertex(); v.number != -1; v = graph.next_vertex(v)) {
        edge_count += graph.adjacencyLists[v.number].edge_count;
    }
    return edge_count / 2; // Dividir entre 2 porque es no dirigido
}

// 2. Contar vértices adyacentes de un vértice dado
int GraphFunctions::count_adjacent_vertices(ListGraph& graph, Vertex v) {
    if (v.number >= (int)graph.vertex_count) return 0; // Vértice inválido
    return graph.adjacencyLists[v.number].edge_count;
}

// 3. Verificar si un grafo es conexo usando DFS
void dfs_helper(ListGraph& graph, Vertex v, bool* visited) {
    visited[v.number] = true;
    for (Vertex adj = graph.first_adyacent_vertex(v); adj.number != -1; adj = graph.next_adyacent_vertex(v, adj)) {
        if (!visited[adj.number]) {
            dfs_helper(graph, adj, visited);
        }
    }
}

bool GraphFunctions::is_connected_dfs(ListGraph& graph) {
    bool* visited = new bool[graph.vertex_count]();
    dfs_helper(graph, graph.first_vertex(), visited);
    for (size_t i = 0; i < graph.vertex_count; ++i) {
        if (!visited[i]) {
            delete[] visited;
            return false;
        }
    }
    delete[] visited;
    return true;
}

// 4. Verificar si un grafo es conexo usando BFS
bool GraphFunctions::is_connected_bfs(ListGraph& graph) {
    bool* visited = new bool[graph.vertex_count]();
    std::queue<Vertex> q;

    q.push(graph.first_vertex());
    visited[graph.first_vertex().number] = true;

    while (!q.empty()) {
        Vertex v = q.front();
        q.pop();

        for (Vertex adj = graph.first_adyacent_vertex(v); adj.number != -1; adj = graph.next_adyacent_vertex(v, adj)) {
            if (!visited[adj.number]) {
                visited[adj.number] = true;
                q.push(adj);
            }
        }
    }

    for (size_t i = 0; i < graph.vertex_count; ++i) {
        if (!visited[i]) {
            delete[] visited;
            return false;
        }
    }
    delete[] visited;
    return true;
}

// 5. Algoritmo de Dijkstra
void GraphFunctions::dijkstra(ListGraph& graph, Vertex source, double* distances) {
    bool* visited = new bool[graph.vertex_count]();
    for (size_t i = 0; i < graph.vertex_count; ++i) {
        distances[i] = std::numeric_limits<double>::infinity();
    }
    distances[source.number] = 0;

    for (size_t i = 0; i < graph.vertex_count; ++i) {
        Vertex current(-1);
        double min_distance = std::numeric_limits<double>::infinity();
        for (size_t j = 0; j < graph.vertex_count; ++j) {
            if (!visited[j] && distances[j] < min_distance) {
                current = Vertex(j);
                min_distance = distances[j];
            }
        }

        if (current.number == -1) break;
        visited[current.number] = true;

        for (Vertex adj = graph.first_adyacent_vertex(current); adj.number != -1; adj = graph.next_adyacent_vertex(current, adj)) {
            double weight = graph.weight(current, adj);
            if (!visited[adj.number] && distances[current.number] + weight < distances[adj.number]) {
                distances[adj.number] = distances[current.number] + weight;
            }
        }
    }

    delete[] visited;
}

// 6. Algoritmo de Floyd-Warshall
void GraphFunctions::floyd_warshall(ListGraph& graph, double** distances) {
    size_t n = graph.vertex_count;

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (i == j) {
                distances[i][j] = 0.0;
            } else {
                distances[i][j] = std::numeric_limits<double>::infinity();
            }
        }
    }

    for (Vertex v = graph.first_vertex(); v.number != -1; v = graph.next_vertex(v)) {
        for (Vertex adj = graph.first_adyacent_vertex(v); adj.number != -1; adj = graph.next_adyacent_vertex(v, adj)) {
            distances[v.number][adj.number] = graph.weight(v, adj);
        }
    }

    for (size_t k = 0; k < n; ++k) {
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                if (distances[i][k] + distances[k][j] < distances[i][j]) {
                    distances[i][j] = distances[i][k] + distances[k][j];
                }
            }
        }
    }
}

// 7. Caminos más cortos entre todo par de vértices usando Dijkstra
void GraphFunctions::all_pairs_dijkstra(ListGraph& graph, double** distances) {
    for (size_t i = 0; i < graph.vertex_count; ++i) {
        dijkstra(graph, Vertex(i), distances[i]);
    }
}

// 8. Prim para el árbol de mínimo costo
void GraphFunctions::prim(ListGraph& graph, int* parent) {
    size_t n = graph.vertex_count;
    double* key = new double[n];
    bool* in_mst = new bool[n]();

    // Inicializar claves y padres
    for (size_t i = 0; i < n; ++i) {
        key[i] = std::numeric_limits<double>::infinity();
        parent[i] = -1;
    }

    key[0] = 0.0; // Empezar desde el vértice 0

    for (size_t count = 0; count < n - 1; ++count) {
        // Encontrar el vértice con la clave más pequeña que no está en el MST
        double min_key = std::numeric_limits<double>::infinity();
        int u = -1;
        for (size_t v = 0; v < n; ++v) {
            if (!in_mst[v] && key[v] < min_key) {
                min_key = key[v];
                u = v;
            }
        }

        in_mst[u] = true;

        // Actualizar las claves de los vértices adyacentes
        for (Vertex adj = graph.first_adyacent_vertex(Vertex(u)); adj.number != -1; adj = graph.next_adyacent_vertex(Vertex(u), adj)) {
            if (!in_mst[adj.number] && graph.weight(Vertex(u), adj) < key[adj.number]) {
                key[adj.number] = graph.weight(Vertex(u), adj);
                parent[adj.number] = u;
            }
        }
    }

    delete[] key;
    delete[] in_mst;
}

// 9. Kruskal para encontrar el árbol de expansión mínima
int find_parent(int vertex, int* parent) {
    if (parent[vertex] != vertex) {
        parent[vertex] = find_parent(parent[vertex], parent); // Compresión de ruta
    }
    return parent[vertex];
}

void union_vertices(int u, int v, int* parent, int* rank) {
    int root_u = find_parent(u, parent);
    int root_v = find_parent(v, parent);

    if (rank[root_u] > rank[root_v]) {
        parent[root_v] = root_u;
    } else if (rank[root_u] < rank[root_v]) {
        parent[root_u] = root_v;
    } else {
        parent[root_v] = root_u;
        ++rank[root_u];
    }
}

void GraphFunctions::kruskal(ListGraph& graph, std::vector<EdgeDetail>& mst) {
    size_t n = graph.vertex_count;
    std::vector<EdgeDetail> edges;

    // Obtener todas las aristas
    for (Vertex v = graph.first_vertex(); v.number != -1; v = graph.next_vertex(v)) {
        for (Vertex adj = graph.first_adyacent_vertex(v); adj.number != -1; adj = graph.next_adyacent_vertex(v, adj)) {
            if (v.number < adj.number) { // Evitar duplicados
                edges.push_back({v.number, adj.number, graph.weight(v, adj)});
            }
        }
    }

    // Ordenar aristas por peso
    std::sort(edges.begin(), edges.end(), [](const EdgeDetail& a, const EdgeDetail& b) {
        return a.weight < b.weight;
    });

    int* parent = new int[n];
    int* rank = new int[n]();

    for (size_t i = 0; i < n; ++i) {
        parent[i] = i;
    }

    // Construir el MST
    for (const auto& edge : edges) {
        int root_u = find_parent(edge.u, parent);
        int root_v = find_parent(edge.v, parent);

        if (root_u != root_v) { // Si no forman un ciclo
            mst.push_back(edge);
            union_vertices(root_u, root_v, parent, rank);
        }
    }

    delete[] parent;
    delete[] rank;
}


// 10. Circuito Hamilton de menor costo (Búsqueda exhaustiva)
double GraphFunctions::hamiltonian_path(ListGraph& graph, std::vector<int>& best_path) {
    size_t n = graph.vertex_count;
    std::vector<int> vertices(n);
    for (size_t i = 0; i < n; ++i) {
        vertices[i] = i;
    }

    double min_cost = std::numeric_limits<double>::infinity();
    do {
        double cost = 0.0;
        bool valid_path = true;

        // Calcular el costo del circuito actual
        for (size_t i = 0; i < n - 1; ++i) {
            double weight = graph.weight(Vertex(vertices[i]), Vertex(vertices[i + 1]));
            if (weight < 0) { // Si no hay conexión, camino no válido
                valid_path = false;
                break;
            }
            cost += weight;
        }

        // Considerar el regreso al inicio para formar un circuito
        if (valid_path) {
            double return_weight = graph.weight(Vertex(vertices[n - 1]), Vertex(vertices[0]));
            if (return_weight < 0) {
                valid_path = false;
            } else {
                cost += return_weight;
            }
        }

        // Actualizar el costo mínimo si el camino es válido
        if (valid_path && cost < min_cost) {
            min_cost = cost;
            best_path = vertices; // Guardar la mejor ruta
        }

    } while (std::next_permutation(vertices.begin(), vertices.end()));

    return min_cost;
}
