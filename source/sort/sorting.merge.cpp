// BigO = O(nlogn)
#include "../../include/stdafx.h"


void SortingAlgorithm::merge(int start, int middle, int end) {
    // Calculate size of left sub-array and right sub-array 
    int subArray1Size = middle - start + 1; 
    int subArray2Size = end - middle;

    // Allocate size for left sub-array and right sub-array 
    int* subArray1 = new int[subArray1Size];
    int* subArray2 = new int[subArray2Size];

    // Assign value for left sub-array
    for (int i = 0; i < subArray1Size; ++i) {
        subArray1[i] = this->arr[start + i];
    }

    // Assign value for right sub-array
    for (int i = 0; i < subArray2Size; ++i) {
        subArray2[i] = this->arr[middle + i + 1];
    }

    int indexOfSA1 = 0;
    int indexOfSA2 = 0;
    int indexMergedArray = start;
    
    // Merge two arrays
    while (indexOfSA1 < subArray1Size && indexOfSA2 < subArray2Size) {
        if (subArray1[indexOfSA1] <= subArray2[indexOfSA2]) {
            this->arr[indexMergedArray] = subArray1[indexOfSA1];
            indexOfSA1++;
        } else {
            this->arr[indexMergedArray] = subArray2[indexOfSA2];
            indexOfSA2++;
        }
        indexMergedArray++;
    }

    // Check if left sub-array is remaining value
    while (indexOfSA1 < subArray1Size) {
        this->arr[indexMergedArray] = subArray1[indexOfSA1];
        indexOfSA1++;
        indexMergedArray++;
    }
    
    // Check if right sub-array is remaining value
    while (indexOfSA2 < subArray2Size) {
        this->arr[indexMergedArray] = subArray2[indexOfSA2];
        indexOfSA2++;
        indexMergedArray++;
    }

    delete[] subArray1;
    delete[] subArray2;
}

void SortingAlgorithm::mergeSort() {
    this->mergeSort(0, this->size - 1);
}

void SortingAlgorithm::mergeSort(int start, int end) {
    // this->printArray();
    // std::cout << "\n";

    if (start >= end) {
        return;
    }

    int middle = start + (end - start) / 2;
    this->mergeSort(start, middle);
    this->mergeSort(middle + 1, end);
    merge(start, middle, end);
}