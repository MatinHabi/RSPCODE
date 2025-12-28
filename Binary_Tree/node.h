#ifndef NODE_H
#define NODE_H
#include <iostream>
class Node{
protected:
    int data;
    Node* left;
    Node* right;
    friend class Tree;
    friend class Tester;
public:
    Node(int v): data(v), left(nullptr), right(nullptr){}
    Node(): data(999){}
    ~Node(){
        std::cout << "Node Deleted!\n";
    }
};


#endif