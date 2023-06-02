#include "../../include/stdafx.h"

Node::Node() {
    this->data = 0;
    this->left = nullptr;
    this->right = nullptr;
}

Node::Node(int data) {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}

Node::~Node() {
    delete this->left;
    delete this->right;

    this->left = nullptr;
    this->right = nullptr;
}