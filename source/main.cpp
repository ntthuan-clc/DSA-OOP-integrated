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
    HashTableChaining ht(10);
    ht.addVal(5);
    ht.addVal(15);
    ht.addVal(3);
    ht.addVal(7);

    ht.showTable();
    std::cout << ht.findVal(7);    
    std::cout << ht.findVal(8);    
    std::cout << ht.findVal(5);    
    

    
}