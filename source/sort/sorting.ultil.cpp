#include "../../include/stdafx.h"

void SortingAlgorithm::printArray() {
    for (int i = 0; i < this->size; ++i) {
        std::cout << this->arr[i] << ' ';
    }
}

int SortingAlgorithm::getMax() {
    int maxVal = this->arr[0];
    for (int i = 1; i < this->size; ++i) {
        maxVal = std::max(maxVal, this->arr[i]);
    }

    return maxVal;
}