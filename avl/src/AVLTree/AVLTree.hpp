#pragma once
#include "../Dict/Dict.h"
#include "Node.hpp"
/**
 * @class AVLTree
 * @brief A class representing an binary AVLTree.
 * 
 * The AVLTree class provides basic operations for a binary AVLTree, including insertion,
 * search, and deletion of elements. It maintains a root node and keeps track of the
 * size of the AVLTree.
 * 
 * @tparam int The type of data stored in the AVLTree nodes.
 */
class AVLTree : public Dict {
    protected:
        Node* root; /// Pointer to the root node of the tree.
        int size;  /// The number of nodes in the tree.
    public:
        /**
         * @brief Constructs a new Tree object.
         * 
         * This constructor initializes the Tree with a null root and a size of zero.
         */
        AVLTree()
        : root(nullptr)
        , size(0) {

        };

        /**
         * @brief Destructor for the Tree class.
         *
         * This destructor is responsible for cleaning up any resources
         * allocated by the Tree class. It ensures that all memory is
         * properly deallocated and any other necessary cleanup tasks
         * are performed when a Tree object is destroyed.
         */
        ~AVLTree() {
            clear(root);
        };

        /**
         * @brief Clears the AVLTree by deleting all nodes.
         *
         * @effect Recursively deletes all nodes in the AVLTree, starting from the root.
         *
         * @require The AVLTree must be initialized with a valid root node.
         *
         * @modifies Modifies the structure of the AVLTree by deleting all nodes.
         */

        void clear(Node* node);

        /**
         * @brief Inserta un elemento en el árbol AVL, asegurando que el árbol se mantenga balanceado.
         *
         * @effect Inserta un nuevo nodo en la posición correcta siguiendo las reglas de un árbol binario de búsqueda.
         *         Luego, verifica y ajusta el balance del árbol usando rotaciones si es necesario, asegurando
         *         que el árbol mantenga su propiedad de AVL (balanceado en altura).
         *
         * @require El árbol debe estar inicializado con una raíz válida o nula. Los elementos deben ser comparables
         *          mediante los operadores `<` y `>`. La función `balance(Node*)` debe estar definida y ser capaz de
         *          realizar las rotaciones necesarias para mantener el equilibrio del árbol AVL.
         *
         * @modifies Modifica la estructura interna del árbol añadiendo un nuevo nodo y potencialmente realizando rotaciones
         *           para mantener el balance AVL. Aumenta el tamaño del árbol (`size`) cuando se inserta un nuevo nodo.
         *
         * @param element El valor del elemento a insertar en el árbol.
         */
        virtual void insert(int element) override;
        /**
         * @brief Verifica si un elemento está presente en el árbol AVL.
         *
         * @effect No modifica la estructura del árbol. Recorre el árbol AVL para encontrar
         *         el elemento especificado, siguiendo las reglas de un árbol binario de búsqueda.
         *
         * @require El árbol debe estar inicializado y seguir las reglas de un árbol binario de búsqueda.
         *          Los elementos deben ser comparables mediante los operadores `<` y `>`.
         *
         * @modifies No modifica la estructura del árbol ni sus atributos.
         *
         * @param element El valor del elemento que se quiere buscar en el árbol.
         * @return true si el elemento está presente en el árbol, false en caso contrario.
         */
        bool contains(int element) override;
            /**
     * @brief Elimina un elemento del árbol AVL y rebalancea el árbol si es necesario.
     *
     * @effect Busca y elimina el nodo que contiene el valor especificado. Si el nodo tiene
     *         dos hijos, encuentra el sucesor en orden para reemplazar el valor. Después de la eliminación,
     *         el árbol se rebalancea para mantener la propiedad AVL.
     *
     * @require El árbol debe estar inicializado. Los elementos deben ser comparables mediante
     *          los operadores `<` y `>`. La función `balance(Node*)` debe estar definida y ser capaz de
     *          rebalancear el árbol AVL después de la eliminación.
     *
     * @modifies Modifica la estructura del árbol eliminando un nodo y actualizando los enlaces de sus
     *           hijos y padres. Además, ajusta el tamaño del árbol (`size`) y rebalancea la estructura si es necesario.
     *
     * @param element El valor del elemento a eliminar del árbol.
     */
        virtual void erase(int element) override;

        /**
         * @brief Rebalancea el árbol AVL comenzando desde un nodo dado y subiendo hacia la raíz.
         *
         * @effect Asegura que el árbol AVL mantenga la propiedad de estar balanceado después de cada inserción
         *         o eliminación. Recorre desde el nodo especificado hacia la raíz, verificando y corrigiendo
         *         cualquier desequilibrio aplicando rotaciones (Left-Left, Right-Right, Left-Right, Right-Left).
         *
         * @require El árbol debe estar inicializado y seguir las reglas de un árbol binario de búsqueda.
         *          Las funciones `leftRotate(Node*)` y `rightRotate(Node*)` deben estar definidas para
         *          realizar las rotaciones necesarias en el árbol.
         *
         * @modifies Modifica la estructura del árbol ajustando las alturas de los nodos y realizando
         *           rotaciones si el árbol pierde el balance. Puede cambiar la raíz del árbol si es necesario.
         *
         * @param node El nodo desde el cual se inicia el proceso de rebalanceo.
         */
        void balance(Node* node);
        /**
         * @brief Realiza una rotación simple hacia la derecha en el subárbol con raíz en el nodo especificado.
         *
         * @effect Cambia la estructura del subárbol para corregir un desequilibrio causado por una
         *         estructura "Left-Left" en el árbol AVL. Actualiza los punteros de los nodos afectados,
         *         incluyendo padres e hijos, y recalcula las alturas de los nodos.
         *
         * @require El árbol debe estar inicializado y seguir las reglas de un árbol binario de búsqueda.
         *          El nodo `y` debe tener un hijo izquierdo no nulo. La función `height(Node*)` debe estar definida.
         *
         * @modifies Modifica la estructura del subárbol, realizando la rotación y actualizando los punteros
         *           de los nodos involucrados, así como las alturas de los nodos rotados.
         *
         * @param y El nodo raíz del subárbol que será rotado hacia la derecha.
         * @return El nuevo nodo raíz del subárbol después de la rotación.
         */
        Node* rightRotate(Node* y);
        /**
         * @brief Realiza una rotación simple hacia la derecha en el subárbol con raíz en el nodo especificado.
         *
         * @effect Cambia la estructura del subárbol para corregir un desequilibrio causado por una
         *         estructura "Right-Right" en el árbol AVL. Actualiza los punteros de los nodos afectados,
         *         incluyendo padres e hijos, y recalcula las alturas de los nodos.
         *
         * @require El árbol debe estar inicializado y seguir las reglas de un árbol binario de búsqueda.
         *          El nodo `y` debe tener un hijo right no nulo. La función `height(Node*)` debe estar definida.
         *
         * @modifies Modifica la estructura del subárbol, realizando la rotación y actualizando los punteros
         *           de los nodos involucrados, así como las alturas de los nodos rotados.
         *
         * @param y El nodo raíz del subárbol que será rotado hacia la derecha.
         * @return El nuevo nodo raíz del subárbol después de la rotación.
         */
        Node* leftRotate(Node* x);
        /**
         * @brief Devuelve la altura de un nodo en el árbol AVL.
         *
         * @effect Calcula la altura de un nodo dado. Si el nodo es nulo, se considera que su altura es -1.
         *         La altura se utiliza para determinar el equilibrio del árbol y para realizar balanceos.
         *
         * @require El árbol debe estar inicializado y seguir las reglas de un árbol binario de búsqueda.
         *          Cada nodo debe tener un atributo de altura correctamente actualizado.
         *
         * @modifies No modifica ningún estado interno del árbol. Solo devuelve un valor basado en el nodo dado.
         *
         * @param node El nodo del cual se desea conocer la altura.
         * @return Un entero que representa la altura del nodo. Retorna -1 si el nodo es nulo.
         */
        int height(Node* node);

        /**
         * @brief Calcula el factor de balance de un nodo en el árbol AVL.
         *
         * @effect Determina el equilibrio del nodo especificado al calcular la diferencia entre la altura
         *         de su subárbol izquierdo y derecho. Un valor positivo indica que el subárbol izquierdo es
         *         más alto, mientras que un valor negativo indica que el subárbol derecho es más alto.
         *
         * @require El árbol debe estar inicializado y seguir las reglas de un árbol binario de búsqueda.
         *          La función `height(Node*)` debe estar definida y devolver la altura del nodo.
         *
         * @modifies No modifica ningún estado interno del árbol. Solo realiza cálculos basados en los nodos
         *           existentes.
         *
         * @param node El nodo para el cual se calculará el factor de balance.
         * @return Un entero que representa el factor de balance:
         *         - 0 si el nodo es nulo,
         *         - un número positivo si el subárbol izquierdo es más alto,
         *         - un número negativo si el subárbol derecho es más alto.
         */
        int getBalance(Node* node);

         /**
         * @brief Devuelve una representación en forma de cadena del árbol binario.
         *
         * @effect No modifica la estructura del árbol. Construye una cadena que contiene
         *         información sobre el tamaño del árbol y los elementos presentes.
         *
         * @require El árbol debe estar inicializado. La función auxiliar `toString(Node*)`
         *          debe existir y ser capaz de recorrer el árbol a partir de la raíz.
         *
         * @modifies No modifica ningún atributo del árbol. Solo construye y devuelve una cadena
         *           de texto con la información del árbol.
         *
         * @return Una cadena de texto que incluye el tamaño del árbol y sus elementos.
         */
        std::string toString() override;
        /**
         * @brief Devuelve una representación en forma de cadena de un nodo y sus hijos en el árbol binario.
         *
         * @effect No modifica la estructura del árbol. Genera una cadena de texto que representa
         *         la información del nodo actual y sus hijos, de manera recursiva.
         *
         * @require El nodo `node` debe estar inicializado o ser nulo. Si no es nulo, debe tener accesibles
         *          sus hijos izquierdos y derechos (si existen). Este método requiere que los valores de los
         *          nodos sean convertibles a cadena mediante `std::to_string`.
         *
         * @modifies No modifica la estructura del árbol ni ningún atributo de los nodos. 
         *           Solo construye y devuelve una cadena de texto con la información de los nodos.
         *
         * @param node Un puntero al nodo del cual se quiere obtener la representación en cadena.
         * @return Una cadena que describe el nodo actual, sus hijos (si tiene), y el resultado de las llamadas recursivas
         *         sobre sus hijos izquierdo y derecho.
         */
        std::string toString(Node* node);

};