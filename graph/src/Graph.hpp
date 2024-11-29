// Copyright 2024 algoritmicos team. ECCI-UCR. CC BY 4.0
#pragma once
#include "Vertex.hpp"

class Graph {
 public:
  size_t vertex_count = 0;

 public:
    Graph() = default;
    virtual ~Graph() = default;

 public:
  /**
   * @brief Limpia el grafo, eliminando todos los vértices y aristas.
   * 
   * Requiere: Ninguna.
   * Modifica: Este objeto.
   * Efecto: Resetea el grafo a un estado vacío.
   */
  virtual void clear() = 0;

  /**
   * @brief Agrega un vértice con el elemento dado al grafo.
   * 
   * Requiere: `element` es un carácter válido.
   * Modifica: Este objeto.
   * Efecto: Añade un nuevo vértice al grafo con el elemento especificado.
   */
  virtual void append_vertex(char element) = 0;

  /**
   * @brief Elimina un vértice del grafo.
   * 
   * Requiere: `vertex` existe en el grafo.
   * Modifica: Este objeto.
   * Efecto: Elimina el vértice y todas las aristas asociadas a él.
   */
  virtual void delete_vertex(Vertex vertex) = 0;

  /**
   * @brief Modifica el elemento asociado a un vértice.
   * 
   * Requiere: `vertex` existe en el grafo.
   * Modifica: El contenido del vértice especificado.
   * Efecto: Actualiza el elemento del vértice con el nuevo valor.
   */
  virtual void modify_element(Vertex vertex, char newElement) = 0;

  /**
   * @brief Obtiene el elemento asociado a un vértice.
   * 
   * Requiere: `vertex` existe en el grafo.
   * Modifica: Ninguna.
   * Efecto: Devuelve el elemento asociado al vértice.
   */
  virtual char element(Vertex vertex) = 0;

  /**
   * @brief Añade una arista entre dos vértices con un peso especificado.
   * 
   * Requiere: Ambos vértices existen en el grafo.
   * Modifica: Este objeto.
   * Efecto: Agrega una arista con el peso indicado entre los vértices.
   */
  virtual void add_edge(Vertex vertex1, Vertex vertex2, double weight) = 0;

  /**
   * @brief Elimina una arista entre dos vértices.
   * 
   * Requiere: Ambos vértices existen en el grafo.
   * Modifica: Este objeto.
   * Efecto: Remueve la arista entre los vértices especificados.
   */
  virtual void delete_edge(Vertex vertex1, Vertex vertex2) = 0;

  /**
   * @brief Modifica el peso de la arista entre dos vértices.
   * 
   * Requiere: Ambos vértices y su arista existen en el grafo.
   * Modifica: Este objeto.
   * Efecto: Actualiza el peso de la arista entre los vértices.
   */
  virtual void modify_weight(Vertex vertex1, Vertex vertex2, double newWeight) = 0;

  /**
   * @brief Obtiene el peso de la arista entre dos vértices.
   * 
   * Requiere: Ambos vértices existen y están conectados por una arista.
   * Modifica: Ninguna.
   * Efecto: Devuelve el peso de la arista entre los vértices.
   */
  virtual double weight(Vertex vertex1, Vertex vertex2) = 0;

  /**
   * @brief Obtiene el primer vértice del grafo.
   * 
   * Requiere: El grafo no está vacío.
   * Modifica: Ninguna.
   * Efecto: Devuelve el primer vértice del grafo.
   */
  virtual Vertex first_vertex() = 0;

  /**
   * @brief Obtiene el siguiente vértice en el grafo.
   * 
   * Requiere: `vertex` existe en el grafo.
   * Modifica: Ninguna.
   * Efecto: Devuelve el siguiente vértice en el grafo.
   */
  virtual Vertex next_vertex(Vertex vertex) = 0;

  /**
   * @brief Obtiene el primer vértice adyacente al vértice dado.
   * 
   * Requiere: `vertex` existe en el grafo.
   * Modifica: Ninguna.
   * Efecto: Devuelve el primer vértice adyacente al vértice especificado.
   */
  virtual Vertex first_adyacent_vertex(Vertex vertex) = 0;

  /**
   * @brief Obtiene el siguiente vértice adyacente al vértice dado.
   * 
   * Requiere: `vertex` y `ady_vertex` existen en el grafo.
   * Modifica: Ninguna.
   * Efecto: Devuelve el siguiente vértice adyacente al vértice dado.
   */
  virtual Vertex next_adyacent_vertex(Vertex vertex, Vertex ady_vertex) = 0;

 public:
  /**
   * @brief Verifica si el grafo está vacío.
   * 
   * Requiere: Ninguna.
   * Modifica: Ninguna.
   * Efecto: Devuelve true si el grafo no tiene vértices; false en caso contrario.
   */
  inline bool empty() const { return this->amount_vertex() == 0; }

  /**
   * @brief Obtiene la cantidad de vértices en el grafo.
   * 
   * Requiere: Ninguna.
   * Modifica: Ninguna.
   * Efecto: Devuelve el número total de vértices en el grafo.
   */
  inline int amount_vertex() const { return vertex_count; }
};
