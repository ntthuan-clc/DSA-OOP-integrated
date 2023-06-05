#include "../../include/stdafx.h"

Node* BST::getRoot() {
    return this->root;
}  // use for inoder, preoder, isEmpty, find

// when delete Node is a leaf
void BST::supportRemoveNoChild(Node* tParent, int data) {
    if (tParent->left && tParent->left->data == data) {
        Node* tDelete = tParent;
        tDelete = tParent->left;

        // Case 1: Delete a leaf in the left tParentDelete
        if (!tDelete->left && !tDelete->right) {
            tParent->left = nullptr;
            delete tDelete;
            tDelete = nullptr;
            return;
        } else {
            if (!tDelete->left && !tDelete->right) {
                tParent->right = nullptr;
                delete tDelete;
                tDelete = nullptr;
                return;
            }
        }
    }
}

// when delete Node have 2 children
void BST::supportRemove2Children(Node* tRoot) {
    /*
        step 1: find successor
        step 2: swap tDelete->data vs successor->data
        step 3: delete call  remove(successor->data);
    */
    Node* successor = tRoot->right;

    while (successor->left) {
        successor = successor->left;
    }

    std::swap(successor->data, tRoot->data);
    this->remove(successor->data);
}

void BST::insert(int data) {
    Node* pNode = new Node(data);
    if (this->root == nullptr) {
        this->root = pNode;
        return;
    }

    Node* head = this->root;

    while (head) {
        if (head->data > pNode->data) {
            if (head->left != nullptr) {
                head = head->left;
            } else {
                head->left = pNode;
                return;
            }
        } else {
            if (head->right != nullptr) {
                head = head->right;
            } else {
                head->right = pNode;
                return;
            }
        }
    }
}

void BST::remove(int data) {
    if (this->root == nullptr) {
        return;
    }

    // if value to delete is root
    if (this->root->data == data) {
        // Case 1: Delete root have 0 child
        if (!this->root->left && !this->root->right) {
            delete this->root;
            this->root = nullptr;
            return;
        }

        // Case 2: Delete root have 1 child
        if (!this->root->left) {  // child in the right
            Node* tmp = this->root;
            this->root = this->root->right;
            delete tmp;
            tmp = nullptr;
            return;
        }

        if (!this->root->right) {  // child in the left
            Node* tmp = this->root;
            this->root = this->root->left;
            delete tmp;
            tmp = nullptr;
            return;
        }

        // Case 3: Delete root have 2 children
        this->supportRemove2Children(this->root);
        return;
    }

    Node* tParentDelete = this->getRoot();
    while (tParentDelete) {
        if (tParentDelete->left && tParentDelete->left->data == data) {
            break;
        }

        if (tParentDelete->right && tParentDelete->right->data == data) {
            break;
        }

        if (tParentDelete->data < data) {
            tParentDelete = tParentDelete->right;
        } else {
            tParentDelete = tParentDelete->left;
        }
    }

    if (!tParentDelete) {
        std::cout << "Not found\n";
        return;
    }

    Node* tDelete = nullptr;

    if (tParentDelete->left && tParentDelete->left->data == data) {
        tDelete = tParentDelete->left;

        // Case 1: Delete a leaf in the left tParentDelete
        this->supportRemoveNoChild(tParentDelete, tDelete->data);

        // case 2: Delete node have 1 child
        if (!tDelete->left) {  // child in the right of tDelete
            Node* tChild = tDelete->right;
            tParentDelete->left = tChild;
            tDelete->right = nullptr;
            delete tDelete;
            tDelete = nullptr;
            return;
        }

        if (!tDelete->right) {  // child in the left of tDelete
            Node* tChild = tDelete->left;
            tParentDelete->left = tChild;
            tDelete->left = nullptr;
            delete tDelete;
            tDelete = nullptr;
            return;
        }
    } else {
        tDelete = tParentDelete->right;

        // Case 1: Delete a leaf in the right of tParentDelete
        this->supportRemoveNoChild(tParentDelete, tDelete->data);

        // Case 2: Delete Node have 1 child;
        if (!tDelete->left) {  // child in the right of tDelete
            Node* tChild = tDelete->right;
            tParentDelete->right = tChild;
            tDelete->right = nullptr;
            delete tDelete;
            tDelete = nullptr;
            return;
        }

        if (!tDelete->right) {  // child in the left of tDelete
            Node* tChild = tDelete->left;
            tParentDelete->right = tChild;
            tDelete->left = nullptr;
            delete tDelete;
            tDelete = nullptr;
            return;
        }
    }

    // Case 3: Delete Node have 2 children
    this->supportRemove2Children(tDelete);
}

bool BST::isEmpty() {
    if (this->root == nullptr) {
        return true;
    }

    return false;
}

// Big O = log2(n) => best case
bool BST::find(int data) {
    if (this->root == nullptr) {
        return false;
    }

    if (this->root->data == data) {
        return true;
    }

    Node* tRoot = this->getRoot();
    while (tRoot) {
        if (tRoot->data == data) {
            return true;
        }

        if (tRoot->data < data) {
            tRoot = tRoot->right;
        } else {
            tRoot = tRoot->left;
        }
    }

    return false;
}

void BST::inoder(Node* _root) {
    // Left Node Right
    if (_root == nullptr) {
        return;
    }
    this->inoder(_root->left);

    std::cout << _root->data << " ";
    this->inoder(_root->right);
}

void BST::preoder(Node* _root) { return; }

void BST::postorder(Node* _root) { return; }
