#include "../../include/stdafx.h"

SortingAlgorithm::SortingAlgorithm() {
    this->arr = new int[CAPACITY];
    this->size = 0;
}

SortingAlgorithm::~SortingAlgorithm() {
    delete[] this->arr;
    this->arr = nullptr;
}

SortingAlgorithm::SortingAlgorithm(int arr[], int size) {
    if (size > CAPACITY) {
        this->arr = new int[CAPACITY];
        for (int i = 0; i < CAPACITY; ++i) {
            this->arr[i] = arr[i];
        }

        this->size = CAPACITY;
        return;
    }
    this->arr = new int[size];
    for (int i = 0; i < size; ++i) {
        this->arr[i] = arr[i];
    }

    this->size = size;
}
