// BigO = O(nlogn)
#include "../../include/stdafx.h"

int SortingAlgorithm::partition(int low, int high) {
    int pivot = this->arr[(low + high) / 2];
    int i = low, j = high;

    while (i < j) {
        while (this->arr[i] < pivot) ++i;
        while (this->arr[j] > pivot) --j;

        if (i <= j) {
            std::swap(this->arr[i], this->arr[j]);
            ++i, --j;
        }
    }
    
    return i - 1;
}   

void SortingAlgorithm::quickSort() {
    this->quickSort(0, this->size - 1);
}

void SortingAlgorithm::quickSort(int low, int high) {
    if (low < high) {
        int pivot = this->partition(low, high);
        this->quickSort(low, pivot);
        this->quickSort(pivot + 1, high);
    }
}