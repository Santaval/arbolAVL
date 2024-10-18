// Copyright 2024 Randall Araya. ECCI-UCR. CC BY 4.0

#ifndef MEDICIONES_CPP
#define MEDICIONES_CPP

#include <iostream>
#include "TimeTest.h"

#include "../Dict/Dict.h"


// Comment or uncomment if necessary
#include "../DictList/DictList.hpp"
#include "../binario/Bin.hpp"
#include "../AVLTree/AVLTree.hpp"
// #include "../DictAVLTree/DictAVLTree.hpp"


/**
 * @brief Measures the time taken to perform insert, search (contains), and
 *        erase operationson a dictionary, running each operation three times
 *        and calculating the average time.
 *
 * Requires A valid dictionary object `dict` that supports the operations:
 *          insert, contains, and erase. A valid array of integers `array`
 *          with a size equal to `size`.
 *
 * Effects Performs the insert, search (contains), and erase operations on the
 *         dictionary three times for the given array of integers. Measures and
 *         outputs the time for each operation in every iteration. Calculates
 *         and outputs the average time for each operation.
 *
 * Modifies the dictionary by inserting and erasing elements as part of the
 * measurement.
 */
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
    double containsTime = testContains(dict, array, size);
    double eraseTime = testErase(dict, array, size);

    // Output the time taken for each operation in the current iteration
    std::cout << "Time taken to insert iteration: " << i << " = " << insertTime
        << "ms" << std::endl;
    std::cout << "Time taken to search iteration: " << i << " = " <<
        containsTime << "ms" << std::endl;;
    std::cout << "Time taken to delete iteration: " << i << " = " << eraseTime
        << "ms" << std::endl;

    // Accumulate the times for calculating the average later
    insertTotalTime += insertTime;
    containsTotalTime += containsTime;
    eraseTotalTime += eraseTime;
  }

  // Output the average time for each operation (insert, contains, erase)
  std::cout << "Average insert time: " << insertTotalTime / 3 << "ms" <<
      std::endl;;
  std::cout << "Average search time: " << containsTotalTime / 3 << "ms" <<
      std::endl;;
  std::cout << "Average delete time: " << eraseTotalTime / 3 << "ms" <<
      std::endl;;
}


/**
 * @brief Executes performance measurements for a dictionary with different
 *        input sizes, performing the measurements on both random and
 *        ascending order data.
 *
 * Requires A valid dictionary object `dict` that supports the operations:
 *           insert, contains, and erase. A valid array `sizes` that contains
 *           the different input sizes for the measurements.
 *
 * Effects Iterates over the array `sizes`, generating random and sorted arrays
 *          of integers for each size. Calls the function `triplMeasureTime`
 *          for each array (random and sorted), measuring the performance of
 *          insert, contains, and erase operations on the dictionary. Outputs
 *          the size and type of order (random or ascending) for each set of
 *          measurements to the standard output.
 *
 * Modifies the dictionary by inserting and erasing elements as part of the
 *          measurement.
 */
template <size_t lenSizes>
void runMeasurements(Dict& dict, const int (&sizes)[lenSizes]) {
  // Iterate over the array of input sizes
  for (size_t i = 0; i < lenSizes; ++i) {
    std::shared_ptr<int[]> randomNumbers = createItemsRandom(sizes[i]);
    // Output the size and type of measurement (random order)
    std::cout << std::endl << "Measure for " << sizes[i] << " elements in "
        << "random order" << std::endl;
    // Perform the triple measurement on random order data
    triplMeasureTime(dict, randomNumbers, sizes[i]);

    std::shared_ptr<int[]> sortedNumbers = createItemsInOrder(sizes[i]);
    // Output the size and type of measurement (ascending order)
    std::cout << std::endl << "Measure for " << sizes[i] << " elements in "
        << "ascending order" << std::endl;
    // Perform the triple measurement on ascending order data
    triplMeasureTime(dict, sortedNumbers, sizes[i]);
  }
}

#ifndef TEST

int main() {
  // The array defines different sizes of data to be inserted, searched, and
      // deleted in each dictionary.
  const int sizes[] = {4096, 16384, 65536, 262144, 1048576
    /*, 4194304 uncomment for extra points*/};

    // std::cout << "============== LIST ==============" << std::endl;

    // //Create an instance for each dict and run the measurements
    // DictList dictList;
    // runMeasurements(dictList, sizes);

    std::cout << "============== BINARY TREE ==============" << std::endl;

    Bin dictBynaryTree;
    runMeasurements(dictBynaryTree, sizes);


    // std::cout << "============== AVL TREE ==============" << std::endl;

    // AVLTree dictAVLTree;
    // runMeasurements(dictAVLTree, sizes);

    return 0;
}

#endif // TEST

#endif // MEDICACIONES_CPP