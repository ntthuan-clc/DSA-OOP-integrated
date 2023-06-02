#include "../../include/stdafx.h"

int DoubleHashing::hash2(int val) {
    return (val % (this->capacity - 1) + 1);  // custom
}

int DoubleHashing::probing(int val) {
    int index = this->hash(val);
    if (this->HT[index] == 0) {
        return index;
    }

    int i = 0;
    while (this->HT[this->hash(index + i * hash2(val))]) {
        ++i;
    }

    return this->hash(index + i * hash2(val));
}

bool DoubleHashing::findVal(int val) {
    int index = this->hash(val);
    if (this->HT[index] == val) {
        return true;
    }

    int i = 0;
    int run = this->hash(index + i * this->hash2(val));
    while (this->HT[run]) {
        if (this->HT[run] == val) {
            return true;
        }
        ++i;
        run = this->hash(index + i * this->hash2(val));

        // if val is not exist in this arr and arr is full slot
        if (i >= this->capacity) {
            return false;
        }
    }

    return false;
}

void DoubleHashing::removeVal(int val) {}
