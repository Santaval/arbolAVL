// Copyright 2024 Randall Araya. ECCI-UCR. CC BY 4.0
#ifndef DICTLIST_HPP
#define DICTLIST_HPP

#include <iostream>
#include <string>

#include "../Dict/Dict.h"

class DictList : public Dict{
 private:
  // Node structure of the singly linked list
  struct Node {
    int element;
    Node *next;

    Node(int element);
  };

  Node *head;

 public:
  // Constructor
  /**
   * Requires: Nothing.
   * Effects: Initializes an empty list.
   * Modifies: Initializes the head to nullptr
   */
  DictList();

  // Insert a new element/key
  /**
   * Requires: An integer element.
   * Effects: Adds a new element to the dictionary.
   * Modifies: The list, by inserting a new node.
   */
  void insert(int element) override;

  // Search for a element associated with a key and determintaet if exist
  /**
   * Requires: An integer element/key.
   * Effects: Returns a boolean element depending if the element exist or not
   * Modifies: Nothing.
   */
  bool contains(int element) override;

  // Remove a element
  /**
   * Requires: An integer element/key.
   * Effects: Removes the node with the given element from the list. If the
   *          element is not found, it makes nothing.
   * Modifies: The list, by removing a node if the element is found.
   */
  void erase(int element) override;

  // Return a string representation of the dictionary
  /**
   * Requires: Nothing.
   * Effects: Returns a string containing all keys/elements
   * Modifies: Nothing.
   */
  std::string toString() override;

  // Destructor
  /**
   * Requires: Nothing.
   * Effects: Frees all dynamically allocated memory used by the list.
   * Modifies: The list, by deallocating all nodes.
   */
  ~DictList();
};

#endif  // DICTLIST_HPP
