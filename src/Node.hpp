/**
 * @struct Node
 * @brief Represents a node in an AVL tree.
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
        : data(data), left(nullptr), right(nullptr) {
          };
    int data;
    int height;
    Node *left;
    Node *right;
    Node *parent;
};