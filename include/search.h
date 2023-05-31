// Big O = O(log2(n))

#pragma once
#include <iostream>
#include "errordefine.h"

class BinarySearch {
private:
    int* arr;
    int size;
    bool isReady();

public:
    BinarySearch();
    ~BinarySearch();
    BinarySearch(int*, int);

    std::pair<int, MyErr*> binarySearchLinear(int); // Search all array
    std::pair<int, MyErr*> binarySearchLinear(int, int, int); // Search in segment

    std::pair<int, MyErr*> binarySearchRecursion(int); // Search all array
    std::pair<int, MyErr*> binarySearchRecursion(int, int, int); // Search in segment
 };
