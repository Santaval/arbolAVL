// Copyright 2024 algoritmicos team. ECCI-UCR. CC BY 4.0
#pragma once
#include <functional>  // Para std::hash
#include <cstddef>     // Para size_t

#define NULL_VERTEX -1

/**
 * @class Vertex
 * @brief Representa un vértice de un grafo.
 *
 * La clase encapsula un número entero asociado al vértice y proporciona
 * sobrecarga de operadores para facilitar su manipulación.
 */
class Vertex {
 public:
  int number; /**< Número que identifica al vértice. */

 public:
  /**
   * @brief Constructor explícito que inicializa un vértice con un número dado.
   *
   * @param number Número entero para identificar el vértice.
   * @requires El número debe ser válido en el contexto del grafo.
   * @modifica Crea un nuevo vértice con el número especificado.
   * @efecto Inicializa un vértice con el número proporcionado.
   */
  explicit Vertex(int number) : number(number) {}

  /**
   * @brief Constructor por defecto que inicializa un vértice como inválido.
   *
   * @requires Ninguna condición inicial específica.
   * @modifica Establece el número del vértice a `-1` (NULL_VERTEX).
   * @efecto Crea un vértice inválido o vacío.
   */
  Vertex() : number(NULL_VERTEX) {}

  /**
   * @brief Destructor para la clase Vertex.
   *
   * @requires Ninguna condición previa.
   * @modifica Libera los recursos asociados con el vértice (si los hay).
   * @efecto Elimina el vértice.
   */
  ~Vertex();

  /**
   * @brief Incrementa el número del vértice en 1.
   *
   * @requires El vértice debe ser válido (no `NULL_VERTEX`).
   * @modifica Incrementa el valor de `number` en 1.
   * @efecto Devuelve el nuevo valor de `number` tras incrementarlo.
   * @return El nuevo valor de `number` tras el incremento.
   */
  int operator++();

  /**
   * @brief Decrementa el número del vértice en 1.
   *
   * @requires El vértice debe ser válido (no `NULL_VERTEX`).
   * @modifica Decrementa el valor de `number` en 1.
   * @efecto Devuelve el nuevo valor de `number` tras decrementarlo.
   * @return El nuevo valor de `number` tras el decremento.
   */
  int operator--();

  /**
   * @brief Compara si dos vértices son iguales en base a su número.
   *
   * @param vertex Otro objeto `Vertex` a comparar.
   * @requires Ambos vértices deben estar inicializados correctamente.
   * @modifica No modifica ninguno de los objetos.
   * @efecto Devuelve `true` si los números de ambos vértices son iguales,
   *         `false` en caso contrario.
   * @return `true` si son iguales, `false` en caso contrario.
   */
  bool operator==(const Vertex &vertex);

  /**
   * @brief Compara si el número del vértice es igual a un número entero dado.
   *
   * @param number Número entero con el que comparar.
   * @requires El vértice debe estar inicializado correctamente.
   * @modifica No modifica el vértice.
   * @efecto Devuelve `true` si el número del vértice coincide con el entero dado,
   *         `false` en caso contrario.
   * @return `true` si son iguales, `false` en caso contrario.
   */
  bool operator==(const int number);

  /**
   * @brief Conversión implícita de `Vertex` a un número entero.
   *
   * @requires El vértice debe ser válido.
   * @modifica No modifica el estado del objeto.
   * @efecto Devuelve el número asociado al vértice.
   * @return Número entero correspondiente al vértice.
   */
  operator int() const;
};

