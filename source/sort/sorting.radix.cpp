// BigO = O(n)
#include "../../include/stdafx.h"

void SortingAlgorithm::countingSort(int exp) {
    int* output = new int[this->size];
    int* countArr = new int[10];

    for (int i = 0; i < 10; ++i) {
        countArr[i] = 0;
    }

    for (int i = 0; i < this->size; ++i) {
        countArr[(this->arr[i] / exp) % 10] += 1;
    }

    for (int i = 1; i < 10; ++i) {
        countArr[i] += countArr[i - 1];
    }

    for (int i = this->size - 1; i >= 0; --i) {
        output[countArr[(this->arr[i] / exp) % 10] - 1] = this->arr[i];
        countArr[(this->arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < this->size; ++i) {
        this->arr[i] = output[i];
    }

    delete[] output;
    delete[] countArr;
}

void SortingAlgorithm::radixSort() {
    int base = this->getMax();
    for (int exp = 1; base / exp > 0; exp *= 10) {
        this->countingSort(exp);
    }
}
