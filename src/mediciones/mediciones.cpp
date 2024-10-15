#include <set>
#include <iostream>
#include "TimeTest.h"

int main() {
    // Mediciones con inserciones en orden aleatorio
    std::set<int> s1;
    std::shared_ptr<int[]> array1 = createItemsRandom(4096);
    std::cout << std::endl << "Time taken to insert: " << testInsert(s1, array1, 4096) << std::endl;

    std::cout << std::endl << "Time taken to search: " << testContains(s1, array1, 4096) << std::endl;

    std::cout << std::endl << "Time taken to delete: " << testErase(s1, array1, 4096) << std::endl;

    // Mediciones con inserciones en orden ascendente
    std::set<int> s2;
    std::shared_ptr<int[]> array2 = createItemsInOrder(4096);
    std::cout << std::endl << "Time taken to insert: " << testInsert(s2, array2, 4096) << std::endl;

    std::cout << std::endl << "Time taken to search: " << testContains(s2, array2, 4096) << std::endl;

    std::cout << std::endl << "Time taken to delete: " << testErase(s2, array2, 4096) << std::endl;

    return 0;
}
