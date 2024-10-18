#include "AVLTree.hpp"
#include <iostream>

void AVLTree::insert(int element) {
    // if root is null, create a new node and set it as root
    if (this->root == nullptr) {
        this->root = new Node(element);
        size++;
        return;
    } else {
        Node* current = this->root; 
        Node* parent = nullptr;

        // find the correct position to insert the new node
        while (current != nullptr) {
            parent = current;
            if (element < current->data) {
                current = current->left;
            } else if (element > current->data) {
                current = current->right;
            } else {
                return; // element already exists in the tree
            }
        }

        // create a new node and set it as the child of the parent node
        Node* newNode = new Node(element);
        if (element < parent->data) {
            parent->left = newNode;
            parent->left->parent = parent;
        } else {
            parent->right = newNode;
            parent->right->parent = parent;
        }

        // balance the tree
        balance(newNode);
    } 

    size++; // increment the size of the tree
    

    
}

bool AVLTree::contains(int element) {
    Node* current = this->root;

    // traverse the AVLTree to find the element
    while (current != nullptr) {
        if (element < current->data) {
            current = current->left;
        } else if (element > current->data) {
            current = current->right;
        } else {
            return true; // element found
        }
    }

    return false; // element not found
}

void AVLTree::erase(int element) {
        Node* current = this->root;

    // Encontrar el nodo a eliminar
    while (current != nullptr && current->data != element) {
        if (element < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    // Si no se encuentra el elemento, salir
    if (current == nullptr) {
        return;
    }

    // Caso 1: El nodo tiene dos hijos
    if (current->left != nullptr && current->right != nullptr) {
        Node* successor = current->right;

        // Encontrar el sucesor en orden
        while (successor->left != nullptr) {
            successor = successor->left;
        }

        // Copiar los datos del sucesor al nodo actual
        current->data = successor->data;

        // Ahora eliminamos el sucesor en lugar del nodo original
        current = successor;
    }

    // Caso 2: El nodo tiene un hijo o no tiene hijos
    Node* child = (current->left != nullptr) ? current->left : current->right;

    // Actualizar el puntero al padre del hijo si no es nullptr
    if (child != nullptr) {
        child->parent = current->parent;
    }

    // Si el nodo a eliminar es la raíz
    if (current->parent == nullptr) {
        this->root = child;
    } else if (current->parent->left == current) {
        current->parent->left = child;
    } else {
        current->parent->right = child;
    }

    // Eliminar el nodo
    delete current;
    size--;

    // Rebalancear el árbol
    this->balance(child);
}

std::string AVLTree::toString() {
    std::string result;
    result += "Size: " + std::to_string(size) + "\n";
    result += "Elements:\n";
    result += toString(this->root);
    return result;
}

std::string AVLTree::toString(Node* node) {
     if (node == nullptr) {
        return "";
    }

    std::string result;

    // Agregar espacios de indentación y la información del nodo
    result += "Node: " + std::to_string(node->data) + "-->";
    // Mostrar el padre
    if (node->parent) {
        result += " Parent: " + std::to_string(node->parent->data);
    } else {
        result += " Parent: None";
    }
    // Mostrar hijos
    if (node->left || node->right) {
        result += "  Children: ";
        if (node->left) {
            result += "Left: " + std::to_string(node->left->data);
        } else {
            result += "Left: None";
        }
        result += ", ";
        if (node->right) {
            result += "Right: " + std::to_string(node->right->data);
        } else {
            result += "Right: None";
        }
    } else {
        result += "  No children";
    }

        result += " Height: " + std::to_string(node->height + 1);
        result += "\n";
    // Concatenar la información de los hijos de manera recursiva
    result += toString(node->left);  // Aumentar indentación para el hijo izquierdo
    result += toString(node->right); // Aumentar indentación para el hijo derecho

    return result;
};


void AVLTree::balance(Node* node) {
    // Recorrer el árbol hacia arriba balanceando desde el nodo actual hasta la raíz
    while (node != nullptr) {
        // Actualizar la altura del nodo actual
        node->height = std::max(height(node->left), height(node->right)) + 1;

        // Obtener el balance del nodo actual
        int balanceFactor = getBalance(node);

        // Caso 1: Left Left
        if (balanceFactor > 1 && getBalance(node->left) >= 0) {
            if (node->parent == nullptr) {
                this->root = rightRotate(node);
            } else if (node->parent->left == node) {
                node->parent->left = rightRotate(node);
            } else {
                node->parent->right = rightRotate(node);
            }
        }

        // Caso 2: Right Right
        else if (balanceFactor < -1 && getBalance(node->right) <= 0) {
            if (node->parent == nullptr) {
                this->root = leftRotate(node);
            } else if (node->parent->left == node) {
                node->parent->left = leftRotate(node);
            } else {
                node->parent->right = leftRotate(node);
            }
        }

        // Caso 3: Left Right
        else if (balanceFactor > 1 && getBalance(node->left) < 0) {
            node->left = leftRotate(node->left);
            if (node->parent == nullptr) {
                this->root = rightRotate(node);
            } else if (node->parent->left == node) {
                node->parent->left = rightRotate(node);
            } else {
                node->parent->right = rightRotate(node);
            }
        }

        // Caso 4: Right Left
        else if (balanceFactor < -1 && getBalance(node->right) > 0) {
            node->right = rightRotate(node->right);
            if (node->parent == nullptr) {
                this->root = leftRotate(node);
            } else if (node->parent->left == node) {
                node->parent->left = leftRotate(node);
            } else {
                node->parent->right = leftRotate(node);
            }
        }

        // Moverse hacia arriba, siguiendo el puntero al padre
        node = node->parent;
    }

}

// Rotación a la derecha
Node* AVLTree::rightRotate(Node* y) {

    Node* x = y->left;
    Node* T2 = x->right;

    // Realizar rotación
    x->right = y;
    y->left = T2;

    x->parent = y->parent;
    y->parent = x;

    if (T2 != nullptr) {
        T2->parent = y;
    }

    y->left = T2;

    // Actualizar alturas
    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;

    // Retornar nueva raíz
    return x;
}

// Rotación a la izquierda
Node* AVLTree::leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Realizar rotación
    y->left = x;
    x->right = T2;

    y->parent = x->parent;
    x->parent = y;

    if (T2 != nullptr) {
        T2->parent = x;
    }
    x->right = T2;

    // Actualizar alturas
    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;

    // Retornar nueva raíz
    return y;
}

int AVLTree::height(Node* node) {
return (node == nullptr) ? -1 : node->height;
}

int AVLTree::getBalance(Node* node) {
    if (node == nullptr) {
        return 0; // Si el nodo es nulo, el balance es 0
    }
    // Devuelve la diferencia entre la altura del subárbol izquierdo y derecho
    return height(node->left) - height(node->right);
}


