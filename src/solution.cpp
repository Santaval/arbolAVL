// Copyright <year> <You>
#include <iostream>
#include "Tree.hpp"

/**
 * @brief Start program execution.
 *
 * @return Status code to the operating system, 0 means success.
 */
int main() {
  Tree tree = Tree();
  tree.insert(6);
  tree.insert(5);
  tree.insert(10);
  tree.insert(7);
  tree.insert(11);
  tree.insert(8);
  tree.insert(4);
  tree.insert(0);
  tree.insert(2);
  tree.insert(1);
  tree.insert(3);

  tree.print();

  std::cout << "Size: " << tree.getSize() << std::endl;

  std::cout << "---------------------" << std::endl;

  tree.erase(6);

  tree.print();

    std::cout << "Size: " << tree.getSize() << std::endl;

     std::cout << "---------------------" << std::endl;

  tree.erase(4);

  tree.print();

    std::cout << "Size: " << tree.getSize() << std::endl;
}
