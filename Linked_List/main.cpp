#include <iostream>
#include "LinkedList.h"
using namespace std;


int main(){
    std::vector<int> vec = {1,2,3,4,5,6,7};

    LinkedList *list = new LinkedList(vec);

    list->print();

    list->remNode(2);

    list->print();

    list->addNode(2);

    list->print();
    cout << "sorting...\n";
    list->sort();

    list->print();

}