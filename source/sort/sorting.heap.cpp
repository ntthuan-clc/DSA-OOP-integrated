// BigO = O(nlogn)
#include "../../include/stdafx.h"

void SortingAlgorithm::heapify(int i, int _size) {
    int largest = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;

    if (left < _size && arr[largest] < arr[left]) {
        largest = left;
    }

    if (right < _size && arr[largest] < arr[right]) {
        largest = right;
    }

    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        this->heapify(largest, _size);
    }
}

void SortingAlgorithm::heapSort() {
    for (int i = this->size / 2 - 1; i >= 0; --i) {
        this->heapify(i, this->size);
    }

    for (int i = this->size - 1; i >= 0; --i) {
        std::swap(arr[0], arr[i]);

        this->heapify(0, i);
    }
}
