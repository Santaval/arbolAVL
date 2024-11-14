// Copyright 2024 Randall Araya. ECCI-UCR. CC BY 4.0
#include "DictList.hpp"

// Node constructor
DictList::Node::Node(int element) : element(element), next(nullptr) {}

// List constructor
DictList::DictList() : head(nullptr) {}

void DictList::insert(int element) {
  if (!this->contains(element)) {
    Node *newNode = new Node(element);

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
    Node *current = head;
    while (current->next != nullptr && current->next->element < element) {
      current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
  }
}

bool DictList::contains(int element) {
  // Starting searching from the head
  Node *current = head;

  // Traversig the list until find the element or end the list
  while (current != nullptr) {
    if (current->element == element) {
      // If element found
      return true;
    }
    current = current->next;
  }

  // If element not found
  return false;
}

void DictList::erase(int element) {
  Node *current = head;
  Node *previous = nullptr;

  // If the list is empty
  if (current == nullptr) {
    return;
  }

  // If the element to erase is the head
  if (current->element == element) {
    head = head->next;
    delete current;
    return;
  }

  // Search for the node to remove
  while (current != nullptr && current->element != element) {
    previous = current;
    current = current->next;
  }

  // If the element do not exist
  if (current == nullptr) {
    return;
  }

  // Fix links and delele node
  previous->next = current->next;
  delete current;
}

std::string DictList::toString() {
  Node* current = head;
  std::string result = "";

  while (current != nullptr) {
    result +=  std::to_string(current->element) + " --> ";
    current = current->next;
  }

  if (result.empty()) {
    return "There are no elements in the dictionary\n";
  }
  result += "nullptr\n";

  return result;
}

DictList::~DictList() {
  Node* current = head;
  while (current != nullptr) {
    Node* next = current->next;
    delete current;
    current = next;
  }
}
