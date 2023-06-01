#include"../../include/stdafx.h"


void HashTableOpenAddressing::addVal(int val) {
    int index = this->probing(val);
    this->HT[index] = val;
}
    
void HashTableOpenAddressing::showTable() {
    for (int i = 0; i < this->capacity; ++i) {
        std::cout << i << ": " << this->HT[i] << "\n";
    }
}