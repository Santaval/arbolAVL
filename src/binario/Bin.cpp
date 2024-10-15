#include "Bin.hpp"

void Bin::insert(int element) {
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
        if (element < parent->data) {
            parent->left = new Node(element);
        } else {
            parent->right = new Node(element);
        }

        size++;
    }
}

bool Bin::contains(int element) {
    Node* current = this->root;

    // traverse the tree to find the element
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

void Bin::erase(int element) {
    Node* current = this->root;
    Node* parent = nullptr;

    // find the node to delete
    while (current != nullptr && current->data != element) {
        parent = current;
        if (element < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    // if the element is not found, return
    if (current == nullptr) {
        return;
    }

    // if the node has two children
    if (current->left != nullptr && current->right != nullptr) {
        Node* successor = current->right;
        Node* successorParent = current;

        // find the inorder successor
        while (successor->left != nullptr) {
            successorParent = successor;
            successor = successor->left;
        }

        // copy the data from the successor to the current node
        current->data = successor->data;

        // update current and parent pointers
        current = successor;
        parent = successorParent;
    }

    // if the node has one child or no children
    Node* child = nullptr;
    if (current->left != nullptr) {
        child = current->left;
    } else if (current->right != nullptr) {
        child = current->right;
    }

    // if the node to be deleted is the root
    if (parent == nullptr) {
        this->root = child;
    } else if (parent->left == current) {
        parent->left = child;
    } else {
        parent->right = child;
    }

    // delete the node
    delete current;
    size--;
}