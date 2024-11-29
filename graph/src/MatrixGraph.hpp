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
  ~MatrixGraph() {}
  /**
 * @brief Clears the graph, removing all vertices and edges.
 *
 * @requires Ninguna condición previa específica.
 * @modifica Libera la memoria utilizada por la matriz de adyacencia y los elementos almacenados.
 * @efecto El grafo queda vacío, sin vértices ni aristas.
 */
void clear() override;

/**
 * @brief Appends a vertex with the given element to the graph.
 *
 * @param element El elemento a asignar al nuevo vértice.
 * @requires La memoria disponible debe ser suficiente para aumentar el tamaño de la matriz de adyacencia.
 * @modifica Aumenta el tamaño de la matriz de adyacencia y agrega el elemento al vector de elementos.
 * @efecto El grafo contiene un vértice adicional con el elemento proporcionado.
 */
void append_vertex(char element) override;

/**
 * @brief Deletes a vertex from the graph.
 *
 * @param vertex El vértice que se desea eliminar del grafo.
 * @requires El vértice especificado debe existir en el grafo.
 * @modifica Reduce el tamaño de la matriz de adyacencia y elimina el elemento asociado al vértice del vector.
 * @efecto El grafo ya no contiene el vértice especificado ni las aristas asociadas a este.
 */
void delete_vertex(Vertex vertex) override;

/**
 * @brief Modifies the element associated with a given vertex.
 *
 * @param vertex El vértice cuyo elemento se desea modificar.
 * @param newElement El nuevo valor que se asignará al vértice.
 * @requires El vértice especificado debe existir en el grafo.
 * @modifica Actualiza el elemento asociado al vértice en el vector de elementos.
 * @efecto El vértice tiene un nuevo elemento asignado.
 */
void modify_element(Vertex vertex, char newElement) override;

/**
 * @brief Retrieves the element associated with the given vertex.
 *
 * @param vertex El vértice cuyo elemento asociado se desea obtener.
 * @requires El vértice especificado debe existir en el grafo.
 * @modifica No modifica el grafo.
 * @efecto Devuelve el elemento asociado al vértice especificado.
 */
char element(Vertex vertex) override;

/**
 * @brief Adds an edge between two vertices with a specified weight.
 *
 * @param vertex1 El primer vértice de la arista.
 * @param vertex2 El segundo vértice de la arista.
 * @param weight El peso asignado a la arista.
 * @requires Ambos vértices deben existir en el grafo.
 * @modifica Actualiza el peso de la arista en la matriz de adyacencia.
 * @efecto Existe una nueva arista entre los vértices especificados con el peso indicado.
 */
void add_edge(Vertex vertex1, Vertex vertex2, double weight) override;

/**
 * @brief Deletes an edge between two vertices in the graph.
 *
 * @param vertex1 El primer vértice de la arista que se desea eliminar.
 * @param vertex2 El segundo vértice de la arista que se desea eliminar.
 * @requires Ambos vértices deben existir en el grafo.
 * @modifica Actualiza la matriz de adyacencia para eliminar la arista entre los vértices.
 * @efecto La arista entre los vértices especificados deja de existir.
 */
void delete_edge(Vertex vertex1, Vertex vertex2) override;

/**
 * @brief Modifies the weight of the edge between two vertices.
 *
 * @param vertex1 El primer vértice de la arista.
 * @param vertex2 El segundo vértice de la arista.
 * @param newWeight El nuevo peso que se asignará a la arista.
 * @requires Ambos vértices deben existir en el grafo.
 * @modifica Actualiza el peso de la arista en la matriz de adyacencia.
 * @efecto La arista entre los vértices tiene un nuevo peso asignado.
 */
void modify_weight(Vertex vertex1, Vertex vertex2, double newWeight) override;

/**
 * @brief Calculates the weight of the edge between two vertices.
 *
 * @param vertex1 El primer vértice.
 * @param vertex2 El segundo vértice.
 * @requires Ambos vértices deben existir en el grafo.
 * @modifica No modifica el grafo.
 * @efecto Devuelve el peso de la arista entre los vértices especificados.
 */
double weight(Vertex vertex1, Vertex vertex2) override;

/**
 * @brief Retrieves the first vertex in the graph.
 *
 * @requires El grafo debe contener al menos un vértice.
 * @modifica No modifica el grafo.
 * @efecto Devuelve el primer vértice del grafo.
 */
Vertex first_vertex() override;

/**
 * @brief Retrieves the next vertex in the graph from the given vertex.
 *
 * @param vertex El vértice actual desde el cual se busca el siguiente vértice.
 * @requires El vértice especificado debe existir en el grafo.
 * @modifica No modifica el grafo.
 * @efecto Devuelve el siguiente vértice en el grafo, según el orden interno.
 */
Vertex next_vertex(Vertex vertex) override;

/**
 * @brief Returns the first adjacent vertex of the given vertex.
 *
 * @param vertex El vértice para el cual se busca el primer vértice adyacente.
 * @requires El vértice especificado debe existir en el grafo.
 * @modifica No modifica el grafo.
 * @efecto Devuelve el primer vértice adyacente al vértice especificado.
 */
Vertex first_adyacent_vertex(Vertex vertex) override;

/**
 * @brief Retrieves the next adjacent vertex to the given vertex.
 *
 * @param vertex El vértice base.
 * @param ady_vertex El vértice adyacente actual.
 * @requires Ambos vértices deben existir en el grafo y ser adyacentes.
 * @modifica No modifica el grafo.
 * @efecto Devuelve el siguiente vértice adyacente al vértice especificado.
 */
Vertex next_adyacent_vertex(Vertex vertex, Vertex ady_vertex) override;


  private:
    /**
 * @brief Increases the size of the adjacency matrix.
 *
 * @requires La matriz de adyacencia debe estar correctamente inicializada.
 * @modifica Reserva una nueva matriz de mayor tamaño y copia los elementos existentes.
 * @efecto La matriz de adyacencia aumenta su tamaño, permitiendo almacenar más vértices.
 */
void increaseMatrixSize();

/**
 * @brief Decreases the size of the adjacency matrix.
 *
 * @requires La matriz de adyacencia debe contener más de un vértice.
 * @modifica Libera la matriz actual, crea una nueva más pequeña y copia los elementos necesarios.
 * @efecto La matriz de adyacencia reduce su tamaño, eliminando las filas y columnas correspondientes a vértices eliminados.
 */
void decreaseMatrixSize(Vertex vertexToRemove);

/**
 * @brief Copies the contents of one matrix to another.
 *
 * @param newMatrix La matriz de destino donde se copiarán los elementos.
 * @param oldMatrix La matriz de origen desde donde se copiarán los elementos.
 * @param size El tamaño de la matriz a copiar (número de filas y columnas).
 * @requires Ambas matrices deben estar correctamente inicializadas y el tamaño especificado debe ser válido.
 * @modifica Escribe los elementos de la matriz de origen en la matriz de destino.
 * @efecto La matriz de destino contiene los mismos valores que la matriz de origen.
 */
void copyMatrix(double **newMatrix, double **oldMatrix, int size);

/**
 * @brief Deletes the current adjacency matrix.
 *
 * @requires La matriz de adyacencia debe haber sido creada previamente.
 * @modifica Libera la memoria asignada dinámicamente para la matriz de adyacencia.
 * @efecto La matriz de adyacencia queda eliminada, y la memoria asociada queda disponible para otros usos.
 */
void deleteMatrix();

};