#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList(){}

LinkedList::LinkedList(std::vector<int> x){
    head = new Node(x[0], nullptr);
    Node* node = head;
    
    for(int i = 1 ; i < x.size(); i++){
        node->next = new Node;
        node = node->next;
        node->data = x[i];
    }
}

void LinkedList::print(){
    Node* p = head;

    while(p){
        std::cout<<p->data<< " ";
        p = p->next;
    }
    std::cout << "\n";
}

void LinkedList::remNode(int x){
    Node* curr = head;
    Node* prev = curr;

    while(curr->next){
        if(curr->data == x){
            break;
        }
        curr = curr->next;
    }
    if(curr->data != x){
        std::cout<< x << " not found in linked list\n";
        return;
    }else{
        prev->next = curr->next;
        delete curr;
        std::cout << "Deleted " << x << " from linked list!\n";
        return;
    }

}

void LinkedList::addNode(int x){
    Node* endNode = head;
    while(endNode->next){
        endNode=endNode->next;
    }
    endNode->next = new Node(x , nullptr);
    std::cout << "added " << x << std::endl;
}

//Implimenting Quick Sort

void LinkedList::sort(){
    Node* end = head;
    Node* secLast = end;
    while(end->next){
        secLast = end;
        end = end->next;
    }

    Node* curr = head;
    Node* prev = head;
    while(curr->next){
        if(end->data > curr->data){
            prev = curr;
            curr = curr->next;
        }else if(end->data <= curr->data){
            //1 2 4 5 6 3
            prev->next = end;
            end->next = curr;
            secLast->next = nullptr;
            break;
        }
    }
    return;
}