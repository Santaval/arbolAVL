#pragma once
#include "../Dict/Dict.h"
#include <string>

/**
 * @class Bin
 * @brief A class representing an binary tree.
 * 
 * The Tree class provides basic operations for a binary tree, including insertion,
 * search, and deletion of elements. It maintains a root node and keeps track of the
 * size of the tree.
 * 
 * @tparam int The type of data stored in the tree nodes.
 */
class Bin : public Dict {
    protected:
        /**
         * @struct Node
         * @brief Represents a node in an binary tree.
         * 
         * This structure defines a node in an AVL tree, which contains the data and pointers to the left and right child nodes.
         * 
         * @var Node::data
         * The data stored in the node.
         * 
         * @var Node::left
         * Pointer to the left child node.
         * 
         * @var Node::right
         * Pointer to the right child node.
         */
        struct Node {
            Node(int data)
            : data(data)
            , left(nullptr)
            , right(nullptr) {
            };
            int data;
            Node* left;
            Node* right;
        };
        Node* root; /// Pointer to the root node of the tree.
        int size;  /// The number of nodes in the tree.
    public:
        /**
         * @brief Constructs a new Tree object.
         * 
         * This constructor initializes the Tree with a null root and a size of zero.
         */
        Bin()
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
        ~Bin() {
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
         * @brief Inserta un elemento en el árbol binario.
         *
         * @effect Si el árbol está vacío, crea un nuevo nodo y lo establece como la raíz.
         *         Si el árbol no está vacío, busca la posición correcta para insertar el nuevo nodo
         *         de acuerdo a las reglas de un árbol binario de búsqueda.
         *         Si el elemento ya existe en el árbol, no realiza ninguna inserción.
         *
         * @require La clase Bin debe tener un puntero `root` inicializado y una variable `size`
         *          que rastrea el número de nodos en el árbol.
         *          El nodo debe ser insertado en la posición correspondiente
         *          manteniendo las propiedades de un árbol binario de búsqueda (elementos menores
         *          a la izquierda, elementos mayores a la derecha).
         *
         * @modifies Modifica la estructura interna del árbol, agregando un nuevo nodo si el elemento
         *           no existía previamente. Aumenta el valor de la variable `size` en uno en caso de inserción exitosa.
         *
         * @param element El valor del elemento a insertar en el árbol.
         */
        void insert(int element) override;

        /**
         * @brief Verifica si un elemento está presente en el árbol binario.
         *
         * @effect No realiza cambios en la estructura del árbol.
         *         Solo recorre el árbol para verificar si el elemento especificado
         *         está presente en él.
         *
         * @require El árbol debe estar inicializado, con un puntero `root` válido.
         *          La estructura del árbol debe seguir las reglas de un árbol binario de búsqueda,
         *          donde los nodos con valores menores se encuentran a la izquierda y los mayores a la derecha.
         *
         * @modifies No modifica la estructura interna del árbol ni ninguna de sus propiedades.
         *
         * @param element El valor del elemento a buscar en el árbol.
         * @return true si el elemento está presente en el árbol, false en caso contrario.
         */
        bool contains(int element) override;
        /**
         * @brief Elimina un elemento del árbol binario de búsqueda.
         *
         * @effect Si el elemento está presente, se elimina del árbol. Dependiendo del caso:
         *         - Si el nodo tiene dos hijos, se reemplaza por su sucesor inorder.
         *         - Si el nodo tiene un solo hijo, ese hijo reemplaza al nodo.
         *         - Si el nodo no tiene hijos, simplemente se elimina.
         *         Si el elemento no se encuentra en el árbol, no se realiza ninguna acción.
         *
         * @require El árbol debe estar inicializado y seguir las reglas de un árbol binario de búsqueda.
         *          El elemento debe ser comparable mediante operadores `<` y `>`.
         *
         * @modifies Modifica la estructura del árbol eliminando el nodo correspondiente si el elemento
         *           está presente. También ajusta el tamaño del árbol disminuyendo el valor de `size` en uno.
         *
         * @param element El valor del elemento a eliminar del árbol.
         */
        void erase(int element) override;

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