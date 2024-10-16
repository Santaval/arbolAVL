#include "AVLTree.hpp"
#include <cstdlib>
#include <algorithm>

void AVLTree::insert(int element) {
    Tree::insert(element); // call the base class insert method
    this->rebalance(this->root);
}

void AVLTree::erase(int element) {
    Tree::erase(element); // call the base class erase method
    this->rebalance(this->root);
}

void AVLTree::rebalance(Node* node) {
    Node* current = node;
    while (current != nullptr) {
        int balance = this->getBalance(current);
        if (balance > 1) {
            if (this->getBalance(current->left) < 0) {
                this->rotateLeft(current->left);
            }
            this->rotateRight(current);
        } else if (balance < -1) {
            if (this->getBalance(current->right) > 0) {
                this->rotateRight(current->right);
            }
            this->rotateLeft(current);
        }
        current = current->parent;
    }
}

void AVLTree::rotateRight(Node* node) {
    Node* leftChild = node->left;
    Node* rightChild = leftChild->right;
    Node* parent = node->parent;

    // rotate the nodes
    leftChild->right = node;
    node->left = rightChild;

    // update the parent node
    if (parent == nullptr) {
        this->root = leftChild;
    } else if (parent->left == node) {
        parent->left = leftChild;
    } else {
        parent->right = leftChild;
    }

    // update the parent pointers
    leftChild->parent = parent;
    node->parent = leftChild;
    if (rightChild != nullptr) {
        rightChild->parent = node;
    }    
}

void AVLTree::rotateLeft(Node* node) {
    Node* rightChild = node->right;
    Node* leftChild = rightChild->left;
    Node* parent = node->parent;

    // rotate the nodes
    rightChild->left = node;
    node->right = leftChild;

    // update the parent node
    if (parent == nullptr) {
        this->root = rightChild;
    } else if (parent->left == node) {
        parent->left = rightChild;
    } else {
        parent->right = rightChild;
    }

    // update the parent pointers
    rightChild->parent = parent;
    node->parent = rightChild;
    if (leftChild != nullptr) {
        leftChild->parent = node;
    }
}

int AVLTree::getBalance(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->left->height - node->right->height;
}

void AVLTree::updateHeight(Node* node) {
    Node* current = node;
    while (current != nullptr) {
        int leftHeight = current->left->height;
        int rightHeight = current->right->height;
        int maxChildHeight = std::max(leftHeight, rightHeight);
        current->height = maxChildHeight + 1;
        current = current->parent;
    }
}