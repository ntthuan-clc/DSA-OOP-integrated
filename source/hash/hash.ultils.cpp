#include "../../include/stdafx.h"

int HashTable::hash(int val) {
    return val % this->capacity;
}

void HashTableChaining::showLinkedList(HashTableChaining::Node * head) {
    if(head == nullptr) {
        return;
    }

    HashTableChaining::Node * pNode = head;
    while (pNode != nullptr) 
    {
        std::cout << pNode->data << " ";
        pNode = pNode->pNext;
    }
    
}

void HashTableChaining::showTable() {
    for(int i = 0; i < this->capacity; ++i) {
        // show linkedlist in HT[i]
        std::cout << i << ":";
        this->showLinkedList(HT[i]);
        std::cout << "\n";
    }
}

bool HashTableChaining::findVal(int index, int val) {
    Node* head = this->HT[index];
    if(head == nullptr) {
        return false;
    }
    while (head != nullptr)
    {
        if(head->data == val) {
            return true;
        }
        head = head->pNext;
    }

    return false;
}

void HashTableChaining::deleteList(HashTableChaining::Node * head) {
    if(head == nullptr) {
        return;
    }

    while (head != nullptr) {
        Node* pTemp = head;
        head = head->pNext;
        delete pTemp;
        pTemp = nullptr;
    }
    

}
