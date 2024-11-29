#ifndef LIST_GRAPH_HPP
#define LIST_GRAPH_HPP

#include <cstddef>
#include "Vertex.hpp"
#include "Graph.hpp"

// Representa una arista en el grafo.
class Edge {
public:
    Vertex vertex;    // Vértice de destino de la arista
    double weight;    // Peso de la arista

    // Constructor por defecto
    // Requiere: Ninguno.
    // Modifica: Inicializa el atributo `vertex` con un vértice por defecto y `weight` con 0.0.
    // Efecto: Crea una arista con el vértice y el peso predeterminados.
    Edge() : vertex(Vertex()), weight(0.0) {}

    // Constructor parametrizado
    // Requiere: Un vértice de tipo `Vertex` y un peso de tipo `double`.
    // Modifica: Asigna el vértice y el peso a la arista.
    // Efecto: Crea una arista con el vértice y el peso especificados.
    Edge(Vertex v, double w) : vertex(v), weight(w) {}
};

// Representa una lista de adyacencia para un vértice en el grafo.
class AdjacencyList {
public:
    Vertex vertex;    // Vértice de la lista de adyacencia
    Edge* edges;      // Arreglo de aristas que conecta al vértice
    size_t edge_count; // Número de aristas en la lista
    size_t edge_capacity; // Capacidad máxima del arreglo de aristas

    // Constructor por defecto
    // Requiere: Ninguno.
    // Modifica: Inicializa los atributos `vertex` con un vértice predeterminado, `edges` con `nullptr`,
    //           `edge_count` con 0 y `edge_capacity` con 0.
    // Efecto: Crea una lista de adyacencia vacía para un vértice.
    AdjacencyList() : vertex(Vertex()), edges(nullptr), edge_count(0), edge_capacity(0) {}

    // Agrega una arista a la lista de adyacencia
    // Requiere: Un vértice de tipo `Vertex` y un peso de tipo `double` para la arista a agregar.
    // Modifica: Si es necesario, aumenta la capacidad de `edges` y agrega la nueva arista.
    // Efecto: Agrega una arista entre el vértice actual y el vértice proporcionado.
    void add_edge(Vertex v, double weight);

    // Elimina una arista de la lista de adyacencia
    // Requiere: Un vértice de tipo `Vertex` para la arista a eliminar.
    // Modifica: Elimina la arista correspondiente de `edges` y ajusta `edge_count`.
    // Efecto: Elimina la arista especificada de la lista de adyacencia.
    void remove_edge(Vertex v);
};

// Implementación de un grafo utilizando listas de adyacencia.
class ListGraph : public Graph {
public:
    AdjacencyList* adjacencyLists; // Arreglo dinámico de listas de adyacencia
    char* elements;               // Arreglo que almacena los elementos de los vértices
    size_t vertex_capacity;        // Capacidad máxima de vértices

    // Asegura que haya suficiente capacidad para agregar un nuevo vértice
    // Requiere: Ninguno.
    // Modifica: Si el número de vértices excede la capacidad, aumenta el tamaño del arreglo `adjacencyLists`.
    // Efecto: Asegura que el grafo pueda contener nuevos vértices.
    void ensure_vertex_capacity();

    // Asegura que haya suficiente capacidad para agregar una nueva arista en una lista de adyacencia
    // Requiere: Una referencia a una lista de adyacencia (`AdjacencyList`).
    // Modifica: Si el número de aristas excede la capacidad de la lista de adyacencia, aumenta la capacidad.
    // Efecto: Asegura que la lista de adyacencia pueda contener nuevas aristas.
    void ensure_edge_capacity(AdjacencyList& list);

public:
    // Constructor
    // Requiere: Ninguno.
    // Modifica: Inicializa el grafo con capacidad predeterminada para vértices y aristas.
    // Efecto: Crea un grafo vacío.
    ListGraph();

    // Destructor
    // Requiere: Ninguno.
    // Modifica: Libera la memoria asociada a los vértices y aristas.
    // Efecto: Destruye el grafo y libera los recursos.
    ~ListGraph();

    // Limpia el grafo (elimina todos los vértices y aristas)
    // Requiere: Ninguno.
    // Modifica: Libera la memoria de todos los vértices y aristas.
    // Efecto: Deja el grafo vacío.
    void clear() override;

    // Agrega un nuevo vértice al grafo
    // Requiere: Un carácter (`char`) que representa el elemento del vértice.
    // Modifica: Añade un nuevo vértice con el valor especificado al grafo.
    // Efecto: Inserta un vértice con el elemento proporcionado en el grafo.
    void append_vertex(char element) override;

    // Elimina un vértice del grafo
    // Requiere: Un objeto `Vertex` que representa el vértice a eliminar.
    // Modifica: Elimina el vértice y sus aristas asociadas.
    // Efecto: Elimina el vértice y sus aristas del grafo.
    void delete_vertex(Vertex vertex) override;

    // Modifica el elemento de un vértice
    // Requiere: Un objeto `Vertex` y un nuevo carácter (`char`) que representa el nuevo valor del vértice.
    // Modifica: Cambia el valor del vértice especificado.
    // Efecto: Modifica el elemento del vértice en el grafo.
    void modify_element(Vertex vertex, char new_element) override;

    // Obtiene el elemento asociado a un vértice
    // Requiere: Un objeto `Vertex`.
    // Modifica: Ninguno.
    // Efecto: Devuelve el valor asociado al vértice.
    char element(Vertex vertex) override;

    // Agrega una arista entre dos vértices con un peso específico
    // Requiere: Dos objetos `Vertex` y un `double` (peso de la arista).
    // Modifica: Añade la arista al grafo.
    // Efecto: Crea una arista entre los dos vértices con el peso especificado.
    void add_edge(Vertex v1, Vertex v2, double weight) override;

    // Elimina una arista entre dos vértices
    // Requiere: Dos objetos `Vertex` que representan los vértices de la arista.
    // Modifica: Elimina la arista entre los vértices.
    // Efecto: Elimina la arista entre los dos vértices del grafo.
    void delete_edge(Vertex v1, Vertex v2) override;

    // Modifica el peso de una arista entre dos vértices
    // Requiere: Dos objetos `Vertex` y un `double` (nuevo peso de la arista).
    // Modifica: Cambia el peso de la arista entre los dos vértices.
    // Efecto: Modifica el peso de la arista entre los vértices.
    void modify_weight(Vertex v1, Vertex v2, double new_weight) override;

    // Obtiene el peso de una arista entre dos vértices
    // Requiere: Dos objetos `Vertex` que representan los vértices de la arista.
    // Modifica: Ninguno.
    // Efecto: Devuelve el peso de la arista entre los dos vértices.
    double weight(Vertex v1, Vertex v2) override;

    // Devuelve el primer vértice del grafo
    // Requiere: Ninguno.
    // Modifica: Ninguno.
    // Efecto: Devuelve el primer vértice en el grafo.
    Vertex first_vertex() override;

    // Devuelve el siguiente vértice después del vértice especificado
    // Requiere: Un objeto `Vertex` que representa el vértice actual.
    // Modifica: Ninguno.
    // Efecto: Devuelve el siguiente vértice en el grafo después del vértice dado.
    Vertex next_vertex(Vertex vertex) override;

    // Devuelve el primer vértice adyacente a un vértice
    // Requiere: Un objeto `Vertex` que representa el vértice.
    // Modifica: Ninguno.
    // Efecto: Devuelve el primer vértice adyacente al vértice dado.
    Vertex first_adyacent_vertex(Vertex vertex) override;

    // Devuelve el siguiente vértice adyacente después de un vértice dado
    // Requiere: Un objeto `Vertex` y un objeto `Vertex` de vértice adyacente.
    // Modifica: Ninguno.
    // Efecto: Devuelve el siguiente vértice adyacente.
    Vertex next_adyacent_vertex(Vertex vertex, Vertex adjacent) override;
};

#endif // LIST_GRAPH_HPP
