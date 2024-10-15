// Copyright <year> <You>
#if 0
#include <iostream>
#include "Bin.hpp"

/**
 * @brief Start program execution.
 *
 * @return Status code to the operating system, 0 means success.
 */
int main() {
  Tree tree = Tree();
  tree.insert(5);
  tree.insert(3);
  tree.insert(7);

  std::cout << "Tree contains 3: " << tree.contains(3) << std::endl;

  tree.erase(3);

  std::cout << "Tree contains 3: " << tree.contains(3) << std::endl;

  std::cout << "Tree contains 5: " << tree.contains(5) << std::endl;
}
#endif
