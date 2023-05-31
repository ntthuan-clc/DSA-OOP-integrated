// BigO = O(n^2)
#include "../../include/stdafx.h"

void SortingAlgorithm::insertionSort() {
    for (int i = 1; i < this->size; ++i) {
        int j = i;
        while (j > 0 && this->arr[j] < this->arr[j - 1]) {
            std::swap(this->arr[j], this->arr[j - 1]);
            j -= 1;
        }
    }
}
