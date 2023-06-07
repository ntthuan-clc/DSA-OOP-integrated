#pragma once

class Node {
   public:
    int data;
    Node* left;
    Node* right;
    Node* parent;
    int depth;

    Node();
    Node(int data);
    ~Node();
};