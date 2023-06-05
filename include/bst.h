#pragma once
#include"binarytreenode.h"

class BST {
private:
    Node* root;
public: 
    BST();
    ~BST();

    void insert(int);
    void remove(int);

    bool isEmpty();
    int find(int);

    void inoder(Node*);
    void preoder(Node*);
    void postorder(Node*);

    //copy root
    Node* getRoot();
};