#include "../../include/search.h"

BinarySearch::BinarySearch() {
    this->arr = new int;
    this->size = 0;
}

BinarySearch::BinarySearch(int* arr, int size) {
    this->arr = new int[size];
    this->size = size;

    for (int i = 0; i < this->size; ++i) {
        this->arr[i] = arr[i];
    }
}

BinarySearch::~BinarySearch() {
    delete[] this->arr;
    this->arr = nullptr;
}
