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

void HashTableChaining::removeVal(int val) {
    int index = this->hash(val);
    Node*& head = this->HT[index];
    if(head == nullptr) {
        return;
    }
    if(head->data == val) {
        Node* pTemp = head;
        head = head->pNext;
        delete pTemp;
        pTemp = nullptr;
        return;
    }

    Node* pNode = head;
    Node* pPrev = head;
    while (pNode)
    {
        pPrev = pNode;
        pNode = pNode->pNext;
        
        if(!pNode) {
            return;
        } 

        if(pNode->data == val) {
            pPrev->pNext = pNode->pNext;
            delete pNode;
            pNode = nullptr;
            return;
        }
    }
    
}
