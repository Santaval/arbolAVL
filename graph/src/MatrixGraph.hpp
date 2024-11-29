// Copyright 2024 algoritmicos team. ECCI-UCR. CC BY 4.0
#pragma once

#include <vector>
#include <cstdio>
#include <ostream>

#include "Graph.hpp"
#include "Vertex.hpp"

class MatrixGraph : public Graph {
  private:
  /**
   * @brief A 2D matrix represented as a vector of vectors of doubles.
   *
   * This data structure is used to store a matrix where each element is a
   * double. Each inner vector represents a row in the matrix, and the outer
   * vector contains all the rows.
   */
  double **matrix = nullptr;
  /**
   * @brief A vector to store elements of type char.
   */
  std::vector<char> elements;

  public:
  /**
   * @brief Construct a new MatrixGraph object.
   *
   * This constructor initializes a new instance of the MatrixGraph class.
   *
   * @param args Arguments for the constructor (if any).
   */
  MatrixGraph(/* args */) : Graph() {}
  /**
   * @brief Destructor for the MatrixGraph class.
   *
   * This destructor is responsible for cleaning up any resources
   * allocated by the MatrixGraph instance.
   */
  ~MatrixGraph() {
    this->clear();
    // Free the memory allocated for the matrix
    for (int i = 0; i < this->amount_vertex(); i++) {
      delete[] this->matrix[i];
    }
    delete[] this->matrix;
  }
  /**
   * @brief Clears the graph, removing all vertices and edges.
   *
   * This function overrides the clear method from the base class.
   * It deallocates all resources associated with the graph and
   * resets it to an empty state.
   */
  void clear() override;
  /**
   * @brief Appends a vertex with the given element to the graph.
   *
   * This function adds a new vertex to the graph and assigns it the specified
   * element.
   *
   * @param element The element to be assigned to the new vertex.
   */
  void append_vertex(char element) override;

  /**
   * @brief Deletes a vertex from the graph.
   *
   * This function removes the specified vertex from the graph, along with any
   * edges connected to it. The graph's structure is updated accordingly to
   * reflect the removal of the vertex.
   *
   * @param vertex The vertex to be deleted from the graph.
   */
  void delete_vertex(Vertex vertex) override;

  /**
   * @brief Modifies the element associated with a given vertex.
   *
   * This function updates the element stored at the specified vertex
   * with a new character value.
   *
   * @param vertex The vertex whose element is to be modified.
   * @param newElement The new character value to be assigned to the vertex.
   */
  void modify_element(Vertex vertex, char newElement) override;
  /**
   * @brief Retrieves the element associated with the given vertex.
   *
   * @param vertex The vertex whose associated element is to be retrieved.
   * @return char The element associated with the specified vertex.
   */
  char element(Vertex vertex) override;
  /**
   * @brief Adds an edge between two vertices with a specified weight.
   *
   * This function creates an edge between the given vertices (vertex1 and vertex2)
   * and assigns the provided weight to that edge. If the edge already exists,
   * the weight will be updated to the new value.
   *
   * @param vertex1 The first vertex of the edge.
   * @param vertex2 The second vertex of the edge.
   * @param weight The weight to be assigned to the edge.
   */
  void add_edge(Vertex vertex1, Vertex vertex2, double weight) override;
  /**
   * @brief Deletes an edge between two vertices in the graph.
   *
   * This function removes the edge that connects the specified vertices
   * vertex1 and vertex2. If there is no edge between the given vertices,
   * the function does nothing.
   *
   * @param vertex1 The first vertex of the edge to be deleted.
   * @param vertex2 The second vertex of the edge to be deleted.
   */
  void delete_edge(Vertex vertex1, Vertex vertex2) override;
  /**
   * @brief Modifies the weight of the edge between two vertices.
   *
   * This function updates the weight of the edge connecting the specified
   * vertices
   * to the new weight provided.
   *
   * @param vertex1 The first vertex of the edge.
   * @param vertex2 The second vertex of the edge.
   * @param newWeight The new weight to be assigned to the edge.
   */
  void modify_weight(Vertex vertex1, Vertex vertex2, double newWeight) override;
  /**
   * @brief Calculates the weight of the edge between two vertices.
   *
   * This function returns the weight of the edge connecting the given vertices
   * in the graph. If there is no edge between the vertices, the behavior of this
   * function depends on the implementation.
   *
   * @param vertex1 The first vertex.
   * @param vertex2 The second vertex.
   * @return double The weight of the edge between vertex1 and vertex2.
   */
  double weight(Vertex vertex1, Vertex vertex2) override;
  /**
   * @brief Retrieves the first vertex in the graph.
   *
   * This function returns the first vertex in the graph. The definition of
   * the "first" vertex depends on the internal representation of the graph.
   *
   * @return Vertex The first vertex in the graph.
   */
  Vertex first_vertex() override;
  /**
   * @brief Retrieves the next vertex in the graph from the given vertex.
   *
   * This function takes a vertex as input and returns the next vertex
   * in the graph. The definition of the "next" vertex depends on the
   * specific implementation of the graph traversal algorithm.
   *
   * @param vertex The current vertex from which the next vertex is to be found.
   * @return Vertex The next vertex in the graph.
   */
  Vertex next_vertex(Vertex vertex) override;
  /**
   * @brief Returns the first ady_vertex vertex of the given vertex.
   *
   * This function retrieves the first vertex that is ady_vertex to the specified vertex.
   *
   * @param vertex The vertex for which the first ady_vertex vertex is to be found.
   * @return Vertex The first ady_vertex vertex of the given vertex.
   */
  Vertex first_adyacent_vertex(Vertex vertex) override;
  /**
   * @brief Retrieves the next ady_vertex vertex to the given vertex.
   *
   * This function returns the next vertex that is ady_vertex to the specified vertex.
   * If the specified ady_vertex vertex is the last ady_vertex vertex, the function may
   * return an invalid vertex or a sentinel value indicating the end of adjacency list.
   *
   * @param vertex The vertex for which to find the next ady_vertex vertex.
   * @param ady_vertex The current ady_vertex vertex.
   * @return Vertex The next ady_vertex vertex to the given vertex.
   */
  Vertex next_adyacent_vertex(Vertex vertex, Vertex ady_vertex) override;

  private:
    void increaseMatrixSize();
    void decreaseMatrixSize(Vertex vertex);
    void copyMatrix(double **newMatrix, double **oldMatrix, int size);
    void deleteMatrix();
};
