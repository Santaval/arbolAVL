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

        };

        /**
         * @brief Inserts an element into the tree.
         * 
         * This pure virtual function must be implemented by any derived class.
         * It inserts the specified element into the tree, maintaining the tree's properties.
         * 
         * @param element The element to be inserted into the tree.
         */
        void insert(int element) override;
        /**
         * @brief Checks if the tree contains a specific element.
         * 
         * This function searches the tree to determine if the specified element
         * is present. It returns true if the element is found, and false otherwise.
         * 
         * @param element The element to search for in the tree.
         * @return true if the element is found, false otherwise.
         */
        bool contains(int element) override;
        /**
         * @brief Removes the specified element from the tree.
         * 
         * This function searches for the given element in the tree and removes it if found.
         * The tree is then rebalanced to maintain the AVL tree properties.
         * 
         * @param element The integer value of the element to be removed from the tree.
         */
        void erase(int element) override;

        /**
         * @brief Returns a string representation of the tree.
         * 
         * This function generates a string representation of the tree by performing
         * an in-order traversal of the tree nodes. The string is then returned to the caller.
         * 
         * @return A string representation of the tree.
         */
        std::string toString() override;

        std::string toString(Node* node);
        
};