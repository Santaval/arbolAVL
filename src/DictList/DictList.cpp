#include "DictList.hpp"

// Node constructor
DictList::Node::Node(int k, int v) : key(k), element(v), next(nullptr) {}

// List constructor
DictList::DictList() : head(nullptr), nextKey(0) {}
