#include "../../include/stdafx.h"

Node *BST::getRoot() {
    return this->root;
} // use for inoder, preoder, isEmpty, find

void BST::insert(int data){
    Node* pNode = new Node(data);
    if(this->root == nullptr) {
        this->root = pNode;
        return;
    }

    Node* head = this->root;

    while (head)
    {
        if(head->data > pNode->data) {
            if(head->left != nullptr) {
                head = head->left;
            } else {
                head->left = pNode;
                return;
            }
        } else {
            if(head->right != nullptr) {
                head = head->right;
            } else {
                head->right = pNode;
                return;
            }
        }
    }
    

}

void BST::remove(int data) {
    return;
}

bool BST::isEmpty() {
    if(this->root == nullptr) {
        return true;
    }

    return false;
}

int  BST::find(int data) {
    return 0;
}

void BST::inoder(Node* _root) {
    // Left Node Right
    if(_root == nullptr) {
        return;
    }
    this->inoder(_root->left);
    std::cout << _root->data << " ";
    this->inoder(_root->right);

}

void BST::preoder(Node* _root) {
    return;
}

void BST::postorder(Node* _root) {
    return;
}


