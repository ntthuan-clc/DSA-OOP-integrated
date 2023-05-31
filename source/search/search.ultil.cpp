#include "../../include/search.h"

bool BinarySearch::isReady() {
    for (int i = 1; i < this->size; ++i) {
        if (this->arr[i] < this->arr[i - 1]) {
            return false;
        }
    }    

    return true;
}