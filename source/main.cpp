#include "../include/stdafx.h"

void testSort();
void testSearch();
void testHash();

int main() {
    testHash();

    return 0;
}

void testSort() {
    int arr[] = {1, 4, 2, 3, 5, 6, 2, 5, 6};
    int n = sizeof(arr) / sizeof(int);

    SortingAlgorithm sa(arr, n);
    sa.printArray();
    std::cout << "\n";
    sa.radixSort();
    sa.printArray();
}


void testSearch() {
    int arr[] = {1, 2, 3, 5, 6, 12, 12, 17};
    int n = sizeof(arr) / sizeof(int);

    BinarySearch bs(arr, n);

    std::pair<int, MyErr*> result = bs.binarySearchRecursion(1,6,3);

    if (result.second->err != nullptr) {
        std::cout << result.second->Error() << "\n";
    }
    else {
        std::cout << result.first << "\n";
    }
}

void testHash() {
    //HashTable *hashtable = new HashTableChaining(10);
    //HashTable *hashtable = new LinearProbing(10);
    //HashTable *hashtable = new QuadraticProbing(10);
    HashTable *hashtable = new DoubleHashing(10);
    hashtable->addVal(5);
    hashtable->addVal(15);
    hashtable->addVal(3);
    hashtable->addVal(7);
    hashtable->addVal(25);
    // hashtable->removeVal(5);
    // hashtable->removeVal(25);
    hashtable->showTable();
    std::cout << hashtable->findVal(7);    
    std::cout << hashtable->findVal(8);    
    std::cout << hashtable->findVal(25);    
    

    
}