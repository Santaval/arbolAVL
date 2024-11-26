// Copyright 2024 algoritmicos team. ECCI-UCR. CC BY 4.0
#pragma once

#include <unordered_map>
#include <vector>
#include <ostream>
#include <utility>
#include "Graph.hpp"
#include "Vertex.hpp"

class ListGraph : public Graph<Vertex, char> {
 private:
  /**
   * @brief Lista de adyacencia.
   *
   * Este contenedor representa el grafo mediante un mapa donde cada vértice
   * tiene una lista de pares que indican el vértice adyacente y el peso de la arista.
   */
  std::unordered_map<Vertex, std::vector<std::pair<Vertex,
      double>>> adjacencyList;
  /**
   * @brief Vector para almacenar los elementos de tipo char.
   */
  std::vector<char> elements;

 public:
  /**
   * @brief Constructor de la clase ListGraph.
   */
  ListGraph() : Graph() {}
  /**
   * @brief Destructor de la clase ListGraph.
   */
  ~ListGraph() {}

  // Métodos requeridos por la especificación
  void clear() override;
  void append_vertex(char element) override;
  void delete_vertex(Vertex vertex) override;
  void modify_element(Vertex vertex, char newElement) override;
  char element(Vertex vertex) override;
  void add_edge(Vertex vertex1, Vertex vertex2, double weight) override;
  void delete_edge(Vertex vertex1, Vertex vertex2) override;
  void modify_weight(Vertex vertex1, Vertex vertex2, double newWeight) override;
  double weight(Vertex vertex1, Vertex vertex2) override;
  Vertex first_vertex() override;
  Vertex next_vertex(Vertex vertex) override;
  Vertex first_adjacent(Vertex vertex) override;
  Vertex next_adjacent(Vertex vertex, Vertex adjacent) override;

  /**
   * @brief Imprime la lista de adyacencia.
   */
  void print_graph();
};
