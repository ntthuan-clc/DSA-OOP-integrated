#include "../../include/search.h"

std::pair<int, MyErr*> BinarySearch::binarySearchRecursion(int val) {
    if (!this->isReady()) { // array is not in sorting status
        MyErr* err = new MyErr("Can not search in this array!");
        return std::make_pair(-1, err);
    }
    return this->binarySearchRecursion(0, this->size - 1, val);
}


std::pair<int, MyErr*> BinarySearch::binarySearchRecursion(int left, int right, int val) {
    int middle = left + (right - left) / 2;
    if(left <= right) {
        if(this->arr[middle] == val) {
            MyErr* err = new MyErr();
            return std::make_pair(middle, err);
        }

        if(this->arr[middle] > val) {
            return binarySearchRecursion(left, middle - 1, val);
        } else {
            return binarySearchRecursion(middle + 1, right, val);
        }
    }
    return std::make_pair(-1, new MyErr("Not found !"));

    
}
