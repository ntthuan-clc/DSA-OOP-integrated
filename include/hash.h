#pragma once
#include <iostream>

class HashTable {
protected: // outside class cannot access, inherited class and this class can access
    int capacity; // num of slot 
    int hash(int);

    

public: 
    //HashTable(); // must add this constructor if have another custom constructor
    HashTable(int capacity);

    //pure function
    virtual void addVal(int) = 0;
    virtual void showTable() = 0;
    virtual bool findVal(int) = 0;
    virtual void removeVal(int) = 0;

};

class HashTableChaining : public HashTable {
private:
    class Node {
    public: // public all things inside class Node or cannot use it
        int data;
        Node *pNext;

        Node (int data) {
            this->data = data;
            this->pNext = nullptr;
        }

        Node() {
            this->data = 0;
            this->pNext = nullptr;
        }
    };
    
    Node** HT;
    void insert(int, int);
    void showLinkedList(Node *);
    bool findVal(int, int); // find element in linked list
    void deleteList(Node*);
public: 
    HashTableChaining(int capacity);
    ~HashTableChaining();

    void addVal(int);
    void showTable();
    bool findVal(int);
    void removeVal(int);
    
};

class HashTableOpenAddressing : public HashTable {

};