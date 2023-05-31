#include "../../include/stdafx.h"
void HashTableChaining::addVal(int val) {
    int index = this->hash(val);
    this->insert(index, val);
}

void HashTableChaining::insert(int index, int val) {
    Node*& head = this->HT[index];
    Node* pNode = new Node(val);

    if(head == nullptr) {
        head = pNode;
        return;
    }

    pNode->pNext = head;
    head = pNode; 

}

bool HashTableChaining::findVal(int val) {
    int index = this->hash(val);
    return this->findVal(index, val);
}
