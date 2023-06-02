#pragma once
#include"binarytreenode.h"

class BinaryTree {
private:
    Node* root;
public: 
    BinaryTree();
    ~BinaryTree();

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