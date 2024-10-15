// Copyright 2024 Randall Araya. ECCI-UCR. CC BY 4.0
#ifndef DICTLIST_HPP
#define DICTLIST_HPP

#include <iostream>
#include <string>

class DictList {
 private:
  // Node structure of the singly linked list
  struct Node {
    int key;
    int element;
    Node *next;

    Node(int key, int element);
  };

  Node *head;
  int nextKey;

 public:
  // Constructor
  /**
   * Requires: Nothing.
   * Effects: Initializes an empty list.
   * Modifies: Initializes the head to nullptr nextKey to 0
   */
  DictList();

  // Insert a new value (key is auto-generated)
  /**
   * Requires: An integer value.
   * Effects: Adds a new value to the dictionary. A key is automatically
   * generated for the value.
   * Modifies: The list, by inserting a new node with an auto-generated key.
   */
  void insert(int element);

  // Search for a value associated with a key and determintaet if exist
  /**
   * Requires: An integer key.
   * Effects: Returns a boolean value depending if the element exist or not
   * Modifies: Nothing.
   */
  bool contains(int element);

  // Remove a value
  /**
   * Requires: An integer value.
   * Effects: Removes the node with the given value from the list. If the
   *          value is not found, prints an error message.
   * Modifies: The list, by removing a node if the value is found.
   */
  void erase(int element);

  // Return a string representation of the dictionary
  /**
   * Requires: Nothing.
   * Effects: Returns a string containing all key-value pairs in the format
   *          "key: value" on each line.
   * Modifies: Nothing.
   */
  std::string toString() const;

  // Destructor
  /**
   * Requires: Nothing.
   * Effects: Frees all dynamically allocated memory used by the list.
   * Modifies: The list, by deallocating all nodes.
   */
  ~DictList();
};

#endif  // DICTLIST_HPP
