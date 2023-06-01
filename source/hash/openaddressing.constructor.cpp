#include "../../include/stdafx.h"

HashTableOpenAddressing::HashTableOpenAddressing(int _capacity) : HashTable(_capacity) {
    this->HT = new int(this->capacity);
    for(int i = 0; i < this->capacity; ++i) {
        this->HT[i] = 0;
    }
}

LinearProbing::LinearProbing(int _capacity) : HashTableOpenAddressing(_capacity) {}

HashTableOpenAddressing::~HashTableOpenAddressing() {
    delete[] this->HT;
    this->HT = nullptr;
}


