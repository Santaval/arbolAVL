#include <iostream>
#include "TimeTest.h"

#include "../Dict/Dict.h"

// Comment or uncomment if necessary
#include "./DictList/DictList.hpp"
// #include "./BynaryTree/BynaryTree.hpp"
// #include "./AVLTree/AVLTree.hpp"

void triplMeasureTime(Dict& dict, std::shared_ptr<int[]> array, unsigned int
    size) {
  // Initialize total time accumulators for each operation
  double insertTotalTime = 0;
  double containsTotalTime = 0;
  double eraseTotalTime = 0;

  // Loop to perform each operation 3 times
  for (int i = 1; i < 4; ++i) {
    // Measure the time for each operation
    double insertTime = testInsert(dict, array, size);
    double containsTime = testInsert(dict, array, size);
    double eraseTime = testInsert(dict, array, size);

    // Output the time taken for each operation in the current iteration
    std::cout << "Time taken to insert iteration: " << i << " = " << insertTime
        << std::endl;
    std::cout << "Time taken to search iteration: " << i << " = " <<
        containsTime << std::endl;;
    std::cout << "Time taken to delete iteration: " << i << " = " << eraseTime
        << std::endl;

    // Accumulate the times for calculating the average later
    insertTotalTime += insertTime;
    containsTotalTime += containsTime;
    eraseTotalTime += eraseTime;
  }

  // Output the average time for each operation (insert, contains, erase)
  std::cout << "Average insert time: " << insertTotalTime / 3 << std::endl;;
  std::cout << "Average search time: " << containsTotalTime / 3 << std::endl;;
  std::cout << "Average delete time: " << eraseTotalTime / 3 << std::endl;;
}

template <size_t lenSizes>
void runMeasurements(Dict& dict, const int (&sizes)[lenSizes]) {
  // Iterate over the array of input sizes
  for (size_t i = 0; i < lenSizes; ++i) {
    std::shared_ptr<int[]> randomNumbers = createItemsRandom(sizes[i]);
    // Output the size and type of measurement (random order)
    std::cout << std::endl << "Measure for " << size << " elements in random " 
      << "order" << std::endl;
    // Perform the triple measurement on random order data
    triplMeasureTime(dict, randomNumbers, sizes[i]);

    std::shared_ptr<int[]> sortedNumbers = createItemsInOrder(sizes[i]);
    // Output the size and type of measurement (ascending order)
    std::cout << std::endl << "Measure for " << size << " elements in ascending"
        << "order" << std::endl;
    // Perform the triple measurement on ascending order data
    triplMeasureTime(dict, sortedNumbers, sizes[i]);
  }
}

int main() {
  // Cantidades de elementos para las mediciones
  const int sizes[] = {4096, 16384, 65536, 262144, 1048576 /*, 4194304 uncomment for
                                                         extra points*/};

  
  // Comment or uncomment if necessary
  DictList dict;
  // BynaryTree dict;
  // AVLTree dict;

  return 0;
}
