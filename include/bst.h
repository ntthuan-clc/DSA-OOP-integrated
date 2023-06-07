#pragma once
#include <iostream>

#include "binarytreenode.h"
#include "errordefine.h"

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
    Node* findNode(int);

    void inoder(Node*);
    void preoder(Node*);
    void postorder(Node*);

    // copy root
    Node* getRoot();

    // Find by Linear
    // Find min value in bst
    std::pair<int, MyErr*> findMin(Node*);

    // Find max value in bst
    std::pair<int, MyErr*> findMax(Node*);

    // Find by recursion
    // Find min value in bst
    std::pair<int, MyErr*> findMinRecursive(Node*);

    // Find max value in bst
    std::pair<int, MyErr*> findMaxRecursive(Node*);

    Node* lca(int, int);     // Lowest common ancestor
    bool checkIsBST(Node*);  // Check if tree is BST
    int sumBST(Node*);       // Sum of all node in BST
    int count(Node*);        // Count node in BST
};