// BigO = O(n)
#include "../../include/stdafx.h"

const int MAXVAL = 1000;

void SortingAlgorithm::countingSort() {
    int* output = new int[this->size];
    int* countArr = new int[MAXVAL];

    for (int i = 0; i < MAXVAL; ++i) {
        countArr[i] = 0;
    }

    for (int i = 0; i < this->size; ++i) {
        countArr[this->arr[i]] += 1;
    }
    // index:       0 | 1 | 2 | 3 | 4 | 5 | 6
    // array:       0 | 2 | 1 | 3 | 2 | 4 | 3

    // countArr:    1 | 1 | 2 | 2 | 1 | 0 | 0
    // output:      0 1 2 2 3 3 4

    int indexOutput = 0, indexCountArr = 0;
    while (indexOutput != this->size) {
        while (countArr[indexCountArr] != 0) {
            output[indexOutput] = indexCountArr;
            indexOutput++;
            countArr[indexCountArr]--;
        }
        indexCountArr++;
    }

    for (int i = 0; i < this->size; ++i) {
        this->arr[i] = output[i];
    }

    delete[] output;
    delete[] countArr;
}