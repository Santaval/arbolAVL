#include "DictList.hpp"

// Node constructor
DictList::Node::Node(int key, int value) : key(key), element(value), next(nullptr) {}

// List constructor
DictList::DictList() : head(nullptr), nextKey(0) {}

void DictList::insert(int element) {
    Node* newNode = new Node(nextKey, element);
    nextKey++;

    // If the list is empty
    if (head == nullptr) {
        head = newNode;
        return;
    }

    // If the  new element is the minor of the dictionary
    if (element < head->element) {
        newNode->next = head;
        head = newNode;
        return;
    }

    // If it's another case, find it's correct position
    Node* current = head;
    while (current->next != nullptr && current->next->element < element) {
        current = current->next;
    }

    // Insert the new node
    newNode->next = current->next;
    current->next = newNode;
}