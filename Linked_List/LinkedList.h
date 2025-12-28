#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "node.h"
#include <vector>

class LinkedList{
private:
    Node* head;
public:
    LinkedList();
    LinkedList(std::vector<int>);

    void remNode(int x);
    void addNode(int x);

    void sort();

    void print();

};


#endif //LINKEDLIST