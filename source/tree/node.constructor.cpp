#include "../../include/stdafx.h"

Node::Node() {
    this->data = 0;
    this->depth = 0;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
}

Node::Node(int data) {
    this->depth = 0;
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
}

Node::~Node() {
    delete this->left;
    delete this->right;

    this->left = nullptr;
    this->right = nullptr;
}