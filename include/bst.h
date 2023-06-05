#pragma once
#include"binarytreenode.h"

class BST {
private:
    Node* root;
    void supportRemove2Children(Node*);
    void supportRemoveNoChild(Node*, int);
public: 
    BST();
    ~BST();

    void insert(int);
    void remove(int);

    bool isEmpty();
    bool find(int);

    void inoder(Node*);
    void preoder(Node*);
    void postorder(Node*);

    //copy root
    Node* getRoot();
};