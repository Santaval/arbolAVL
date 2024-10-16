#include "Tree.hpp"
#include <queue>
#include <queue>
#include <iostream>

void Tree::insert(int element) {
    // if root is null, create a new node and set it as root
    if (this->root == nullptr) {
        this->root = new Node(element);
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
        newNode->parent = parent;
        if (element < parent->data) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }

        size++;
    }
}

bool Tree::contains(int element) {
    Node* elementNode = this->findNode(element);
    if (elementNode != nullptr) {
        return true; // element found
    }
    return false; // element not found
}

void Tree::erase(int element) {
    Node* current = this->findNode(element);
    Node* parent = current->parent;

    // left more right
    if (current->left != nullptr) {
        eraseLeftMostRight(current);
    } else if (current->right != nullptr) {
        eraseRightMostLeft(current);
    } else {
        /// if the node is a leaf
        if (parent->left == current) {
            parent->left = nullptr;
        } else {
            parent->right = nullptr;
        }
        delete current;
    }
    
    this->size--;
};

void Tree::eraseLeftMostRight(Node* node) {
    Node* current = node->left;
    while (current->right != nullptr) {
        current = current->right;
    }

    node->data = current->data;

    this->erase(current);
}


void Tree::eraseRightMostLeft(Node* node) {
    Node* current = node->right;
    while (current->left != nullptr) {
        current = current->left;
    }

    node->data = current->data;

    this->erase(current);
}

void Tree::erase(Node* node) {
    Node* parent = node->parent;

    if (node->left) {
        node->left->parent = parent;
    }

    if (node->right) {
        node->right->parent = parent;
    }

    if (parent->left == node) {
        parent->left = node->left;
    } else {
        parent->right = node->right;
    }

    delete node;
}
Node* Tree::findNode(int element) {
    Node* current = this->root;
    // traverse the tree to find the element
    while (current != nullptr) {
        if (element < current->data) {
            current = current->left;
        } else if (element > current->data) {
            current = current->right;
        } else {
            return current; // element found
        }
    }
    return nullptr; // element not found
}

 void Tree::printNode(Node* node, int indent) {
        if (node == nullptr) {
            return;
        }

        // Agregar espacios de indentación
        std::cout << std::string(indent, ' ') << "Node: " << node->data << "\n";

        // Mostrar información del padre
        if (node->parent) {
            std::cout << std::string(indent, ' ') << "  Parent: " << node->parent->data << "\n";
        } else {
            std::cout << std::string(indent, ' ') << "  Parent: None (this is the root)\n";
        }

        // Mostrar hijos
        if (node->left || node->right) {
            std::cout << std::string(indent, ' ') << "  Children: ";
            if (node->left) {
                std::cout << "Left: " << node->left->data;
            } else {
                std::cout << "Left: None";
            }
            std::cout << ", ";
            if (node->right) {
                std::cout << "Right: " << node->right->data;
            } else {
                std::cout << "Right: None";
            }
            std::cout << "\n";
        } else {
            std::cout << std::string(indent, ' ') << "  No children\n";
        }

        // Llamar recursivamente a los hijos
        printNode(node->left, indent + 2);  // Aumentar indentación para el hijo izquierdo
        printNode(node->right, indent + 2); // Aumentar indentación para el hijo derecho
    }

void Tree::print() {
    printNode(this->root, 0);
}