#include "../../include/stdafx.h"
int LinearProbing::probing(int val) {
    int index = this->hash(val);
    int i = 0;
    while (this->HT[this->hash(index + i)]) {
        ++i;
    }

    return this->hash(index + i);
    
}

void LinearProbing::addVal(int val) {
    int index = this->probing(val);
    this->HT[index] = val;
}
    
void LinearProbing::showTable() {
    for (int i = 0; i < this->capacity; ++i) {
        std::cout << i << ": " << this->HT[i] << "\n";
    }
}
    
bool LinearProbing::findVal(int val) {
    int index = this->hash(val);
    if(this->HT[index] == val) {
        return true;
    }

    int i = 0;
    int run = this->hash(index + i);
    while (this->HT[run]) {
        if(this->HT[run] == val) {
            return true;
        }
        ++i;
        run = this->hash(index + i);

        // if val is not exist in this arr and arr is full slot
        if(i >= this->capacity) {
            return false;
        }
    }

    return false;
     
}
    
void LinearProbing::removeVal(int val) {
    // Not neccessary
    // in this solution just suitable for inserting not removing
}