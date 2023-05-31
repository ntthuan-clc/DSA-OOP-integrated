#include "../../include/stdafx.h"

std::pair<int, MyErr*> BinarySearch::binarySearchLinear(int val) {
    if (!this->isReady()) { // array is not in sorting status
        MyErr* err = new MyErr("Can not search in this array!");
        return std::make_pair(-1, err);
    }

    int left = 0, right = this->size - 1;

    while (left <= right) {
        int middle = left + ((right - left) / 2);

        if (this->arr[middle] == val) {
            MyErr* err = new MyErr();
            return std::make_pair (middle, err);
        }

        if (this->arr[middle] < val) { // ignore left side
            left = middle + 1;
        } else { // ignore right side
            right = middle -1;
        }
    }
    MyErr* err = new MyErr("Not found!");
    return std::make_pair(-1, err);
}

std::pair<int, MyErr*> BinarySearch::binarySearchLinear(int left, int right, int val) {
    if (!this->isReady()) { // array is not in sorting status
        MyErr* err = new MyErr("Can not search in this array!");
        return std::make_pair(-1, err);
    }

    while (left <= right) {
        int middle = left + ((right - left) / 2);

        if (this->arr[middle] == val) {
            MyErr* err = new MyErr();
            return std::make_pair (middle, err);
        }

        if (this->arr[middle] < val) { // ignore left side
            left = middle + 1;
        } else { // ignore right side
            right = middle -1;
        }
    }
    MyErr* err = new MyErr("Not found!");
    return std::make_pair(-1, err);

}