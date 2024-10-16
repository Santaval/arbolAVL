// Copyright 2024 Randall Araya. ECCI-UCR. CC BY 4.0
/**
 * @file test.cpp
 * @brief Test file to verify the correctness of the methods in the DictList
 *        class.
 * 
 * This file contains a set of tests to ensure that the methods implemented in
 * the diferentes dictionaries work as expected. The tests include inserting,
 * searching, and removing elements from the list. Additionally, the
 * `toString()` method is used to print the contents of the dictionary before
 * and after each operation, allowing verification that the structure behaves
 * as intended.
 * 
 * Tested functions:
 * - `insert()`: Inserts elements into the list.
 * - `contains()`: Checks if an element is present in the list.
 * - `erase()`: Removes elements from the list.
 * - `toString()`: Returns a string representation of the list's contents.
 */


#include <iostream>
#ifdef TEST
// Comment and uncomment as necessary
#include "./DictList/DictList.hpp"
#include "./Dict/Dict.h"
#include "./binario/Bin.hpp"
#include "./AVLTree/AVLTree.hpp"

void test(Dict &dict, std::string name);
int main() {

  std::cout << "============== LIST ==============" << std::endl;
  DictList dictList;
  test(dictList, "List");

  std::cout << "============== BINARY TREE ==============" << std::endl;
  Bin dictBin;
  test(dictBin, "Binary Tree");

  std::cout << "============== AVL TREE ==============" << std::endl;
  AVLTree dictAVL;
  test(dictAVL, "AVL Tree");
  return EXIT_SUCCESS;

}


void test(Dict &dict, std::string name) {
  // DictBynaryTree dict;
  // DictAVLTree dict;

  // Insert elements
  int elementsToInsert[6] = {7, 0, -3, 1, 21, 4};
  for (size_t i = 0; i < sizeof(elementsToInsert) / sizeof(elementsToInsert[0]);
      ++i) {
    dict.insert(elementsToInsert[i]);
  }

  // Show dictionary after insert elements
  std::cout << "\n" << name << " after insertion:\n" << dict.toString()  <<std::endl;

  // insert an element that already exists
  int existingElement = 21;
  dict.insert(existingElement);

  // Show dictionary after insert an existing element
  std::cout << "\n" << name << " after inserting an existing element:" << existingElement
      << std::endl << dict.toString() << std::endl;



  // Look if the elements exists
  int elementsToFind[2] = {21, 88};
  for (size_t i = 0; i < sizeof(elementsToFind) / sizeof(elementsToFind[0]);
      ++i) {
    std::cout << "Searching for element: " << elementsToFind[i] << std::endl;
    bool exist = dict.contains(elementsToFind[i]);
    if (exist) {
      std::cout << "element: " << elementsToFind[i] << " exist" << std::endl;
    } else {
      std::cout << "element: " << elementsToFind[i] << " do not exist" <<
          std::endl;
    }
    std::cout << std:: endl;
  }

  std::cout << std::endl;

  // Erase a element
  int element = 21;
  dict.erase(element);

  // Show dictionary after erase element
  std::cout <<  name << " after removing an existing element:" << element <<std::endl
      << dict.toString() << std::endl;

  std::cout << std::endl;

  // Try to erase a element that doesn't exist
  element = 88;
  dict.erase(element);

  // Show dictionary after erase element
  std::cout << name << " after trying to remove an not existing element:" << element
      << std::endl << dict.toString() << std::endl;
}

#endif