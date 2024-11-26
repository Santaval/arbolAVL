// Copyright 2024 algoritmicos team. ECCI-UCR. CC BY 4.0
#include "ListGraph.hpp"
#include <iostream>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <vector>
#include <limits>
#include <string>

// Constructor
ListGraph::ListGraph() = default;

// Destructor
ListGraph::~ListGraph() {
  clear();
}

// Clear the ListGraph
void ListGraph::clear() {
  adjacencyList.clear();
}

// Add a vertex
void ListGraph::append_vertex(char element) {
  Vertex vertex(adjacencyList.size());
  adjacencyList[vertex] = {};
}

// Delete a vertex
void ListGraph::delete_vertex(Vertex vertex) {
  adjacencyList.erase(vertex);

  for (auto &[key, edges] : adjacencyList) {
    edges.erase(std::remove_if(edges.begin(), edges.end(),
                               [vertex](const auto &edge) {
                                 return edge.first == vertex;
                               }), edges.end());
  }
}

// Modify a vertex
void ListGraph::modify_element(Vertex vertex, char new_element) {
  // Agregar un atributo element al vertex para que esto tenga sentido
}

// Get the value of a vertex
char ListGraph::element(Vertex vertex) {
  // Agregar un atributo element al vertex para que esto tenga sentido
  return static_cast<char>(vertex);
}

// Add an edge
void ListGraph::add_edge(Vertex v1, Vertex v2, double weight) {
  if (v1 == v2 || weight <= 0)
    return;

  adjacencyList[v1].emplace_back(v2, weight);
  adjacencyList[v2].emplace_back(v1, weight);
}

// Delete an edge
void ListGraph::delete_edge(Vertex v1, Vertex v2) {
  auto &edges1 = adjacencyList[v1];
  edges1.erase(std::remove_if(edges1.begin(), edges1.end(),
                              [v2](const auto &edge) {
                                return edge.first == v2;
                              }),
               edges1.end());

  auto &edges2 = adjacencyList[v2];
  edges2.erase(std::remove_if(edges2.begin(), edges2.end(),
                              [v1](const auto &edge)
                              { return edge.first == v1; }),
               edges2.end());
}

// Modify the weight of an edge
void ListGraph::modify_weight(Vertex v1, Vertex v2, double new_weight) {
  for (auto &edge : adjacencyList[v1]) {
    if (edge.first == v2) {
      edge.second = new_weight;
      break;
    }
  }

  for (auto &edge : adjacencyList[v2]) {
    if (edge.first == v1) {
      edge.second = new_weight;
      break;
    }
  }
}

// Get the weight of an edge
double ListGraph::weight(Vertex v1, Vertex v2) {
  for (const auto &edge : adjacencyList.at(v1)) {
    if (edge.first == v2) {
      return edge.second;
    }
  }
  return std::numeric_limits<double>::infinity();
}

// Get the first vertex
Vertex ListGraph::first_vertex() {
  if (adjacencyList.empty())
    return Vertex();
  return adjacencyList.begin()->first;
}

// Get the next vertex
Vertex ListGraph::next_vertex(Vertex vertex) {
  auto it = adjacencyList.find(vertex);
  if (it != adjacencyList.end() && ++it != adjacencyList.end()) {
    return it->first;
  }
  return Vertex();
}

// Get the first ady_vertex vertex
Vertex ListGraph::first_adyacent_vertex(Vertex vertex) {
  if (!adjacencyList.at(vertex).empty()) {
    return adjacencyList.at(vertex).front().first;
  }
  return Vertex();
}

// Get the next ady_vertex vertex
Vertex ListGraph::next_adyacent_vertex(Vertex vertex, Vertex ady_vertex) {
  const auto &edges = adjacencyList.at(vertex);
  for (size_t i = 0; i < edges.size(); ++i) {
    if (edges[i].first == ady_vertex && i + 1 < edges.size()) {
      return edges[i + 1].first;
    }
  }
  return Vertex();
}
