#include <iostream>
#include "TimeTest.h"
#include "../Dict/Dict.h"

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
    std::cout << "Time taken to insert iteration: " << i << " = " << insertTime;
    std::cout << "Time taken to search iteration: " << i << " = " <<
        containsTime;
    std::cout << "Time taken to delete iteration: " << i << " = " << eraseTime;

    // Accumulate the times for calculating the average later
    insertTotalTime += insertTime;
    containsTotalTime += containsTime;
    eraseTotalTime += eraseTime;
  }

  // Output the average time for each operation (insert, contains, erase)
  std::cout << "Average insert time: " << insertTotalTime / 3;
  std::cout << "Average search time: " << containsTotalTime / 3;
  std::cout << "Average delete time: " << eraseTotalTime / 3;
}


int main() {
  // Cantidades de elementos para las mediciones
  int sizes[] = {4096, 16384, 65536, 262144, 1048576, 4194304};

  return 0;
}
