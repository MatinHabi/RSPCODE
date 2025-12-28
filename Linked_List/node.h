#ifndef NODE_H
#define NODE_H


class Node{
private:
    Node* next;
    int data;
    friend class LinkedList;
public:
    Node(): next(nullptr), data(999){}
    Node(int x, Node*y): data(x), next(y){}
};


#endif //NODE_H