#include "../../include/stdafx.h"

// find by linear
std::pair<int, MyErr*> BST::findMin(Node* _root) {
    if (_root == nullptr) {
        return std::make_pair(-1, new MyErr("This tree is empty"));
    }

    while (_root->left) {
        _root = _root->left;
    }

    return std::make_pair(_root->data, new MyErr());
}

std::pair<int, MyErr*> BST::findMax(Node* _root) {
    if (_root == nullptr) {
        return std::make_pair(-1, new MyErr("This tree is empty"));
    }

    while (_root->right) {
        _root = _root->right;
    }

    return std::make_pair(_root->data, new MyErr());
}

// find by recursive
std::pair<int, MyErr*> BST::findMinRecursive(Node* _root) {
    if (_root == nullptr) {
        return std::make_pair(-1, new MyErr("This tree is empty"));
    }

    if (!_root->left) {
        return std::make_pair(_root->data, new MyErr());
    }

    return this->findMinRecursive(_root->left);
}

std::pair<int, MyErr*> BST::findMaxRecursive(Node* _root) {
    if (_root == nullptr) {
        return std::make_pair(-1, new MyErr("This tree is empty"));
    }

    if (!_root->right) {
        return std::make_pair(_root->data, new MyErr());
    }

    return this->findMaxRecursive(_root->right);
}

Node* BST::lca(int v1, int v2) {
    Node* nodeV1 = this->findNode(v1);
    Node* nodeV2 = this->findNode(v2);

    if (nodeV1 && nodeV2) {
        while (nodeV1->depth > nodeV2->depth) {
            nodeV1 = nodeV1->parent;
        }

        while (nodeV2->depth > nodeV1->depth) {
            nodeV2 = nodeV2->parent;
        }

        while (nodeV1->parent != nodeV2->parent) {
            nodeV1 = nodeV1->parent;
            nodeV2 = nodeV2->parent;
        }

        return nodeV1->parent;
    }

    return nullptr;
}

bool BST::checkIsBST(Node* _root) {
    if (_root == nullptr) {
        return true;
    }

    if (_root->left && _root->left->data > _root->data) {
        return false;
    }

    if (_root->right && _root->right->data < _root->data) {
        return false;
    }

    return this->checkIsBST(_root->left) && this->checkIsBST(_root->right);
}

int BST::sumBST(Node* _root) {
    if (_root == nullptr) {
        return 0;
    }

    return _root->data + sumBST(_root->left) + sumBST(_root->right);
}

int BST::count(Node* _root) {
    if (_root == nullptr) {
        return 0;
    }

    return 1 + count(_root->left) + count(_root->right);
}
