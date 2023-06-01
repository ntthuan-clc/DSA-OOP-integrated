#include "../../include/stdafx.h"

int QuadraticProbing::probing(int val) {
    int index = this->hash(val);
    int i = 0;
    while (this->HT[this->hash(index + i*i)]) {
        ++i;
    }

    return this->hash(index + i*i);
}
    
bool QuadraticProbing::findVal(int val) {
    int index = this->hash(val);
    if(this->HT[index] == val) {
        return true;
    }

    int i = 0;
    int run = this->hash(index + i*i);
    while (this->HT[run]) {
        if(this->HT[run] == val) {
            return true;
        }
        ++i;
        run = this->hash(index + i*i);

        // if val is not exist in this arr and arr is full slot
        if(i >= this->capacity) {
            return false;
        }
    }

    return false;
}

void QuadraticProbing::removeVal(int) {
    // Not neccessary 
}