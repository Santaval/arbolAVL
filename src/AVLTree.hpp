#include "Tree.hpp"

/**
 * @class AVLTree
 * @brief A class representing an AVL Tree, which is a self-balancing binary search tree.
 * 
 * The AVLTree class inherits from the Tree class and provides functionality for
 * inserting and deleting elements while maintaining the AVL tree properties.
 * 
 * @note This class ensures that the tree remains balanced after every insertion and deletion.
 * 
 * @details
 * The AVLTree class includes methods for constructing and destructing an AVL tree,
 * as well as inserting and deleting elements. The tree maintains its balance by
 * performing rotations as necessary during insertions and deletions.
 * 
 * @see Tree
 */
class AVLTree : public Tree {

    public:
        /**
         * @brief Constructs a new AVLTree object.
         * 
         * This constructor initializes the AVLTree with a null root and a size of zero.
         */
        AVLTree()
        : Tree() {
        };

        /**
         * @brief Destructor for the AVLTree class.
         *
         * This destructor is responsible for cleaning up any resources
         * allocated by the AVLTree class. It ensures
         * that all memory is properly deallocated and any other necessary cleanup tasks
         * are performed when a AVLTree object is destroyed.
         */
        ~AVLTree() {
        };

        /**
         * @brief Inserts an element into the AVL tree.
         * 
         * @param element The element to insert into the tree.
         */
        void insert(int element) override;

        /**
         * @brief Erases an element from the AVL tree.
         * 
         * @param element The element to erase from the tree.
         */
        void erase(int element) override;
        
        void rotateRight(Node* node);

        void rotateLeft(Node* node);

        void rebalance(Node* node);

        int getBalance(Node* node);

        void updateHeight(Node* node);
};