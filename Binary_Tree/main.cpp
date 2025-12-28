#include <iostream>
#include "tree.h"
#include "tester.h"
#include <thread>
using namespace std;



int main(){    
    Tester* t1 = new Tester;
    //t1->printList();
    //t1->duration_diff_BST_linSearch(86);
    t1->duration_diff_BST_linSearch(50);
    //t1->duration_diff_BST_linSearch(25);

    // std::vector<int> init;
    // int arky;
    // for(int i = 0 ; i < 3; i++){
    //     std::cin >> arky;
    //     init.push_back(arky);
    // }
    // Tree* tree = new Tree(init);
    // tree->printTree(tree->getRoot());
    // std::this_thread::sleep_for(chrono::seconds(10));
    // int input = 0;
    // bool done = false;
    // while(!done){
    //     std::this_thread::sleep_for(chrono::seconds(5));
    //     std::system("clear");
    //     std::cout<<"next number: ";
    //     std::cin >> input;
    //     tree->insert(input);
    //     tree->printTree(tree->getRoot());

    //     std::string in;
    //     std::cout<<"done?: ";
    //     std::cin>>in;
    //     if(in == "y")done = true;

    // }

}




//MAKING THE BINARY TREE
// std::vector<int> init;
// int arky;
// for(int i = 0 ; i < 3; i++){
//     std::cin >> arky;
//     init.push_back(arky);
// }
// Tree* tree = new Tree(init);
// tree->printTree(tree->getRoot());
// std::this_thread::sleep_for(chrono::seconds(10));
// int input = 0;
// bool done = false;
// while(!done){
//     std::this_thread::sleep_for(chrono::seconds(5));
//     std::system("clear");
//     std::cout<<"next number: ";
//     std::cin >> input;
//     tree->insert(input);
//     tree->printTree(tree->getRoot());

//     std::string in;
//     std::cout<<"done?: ";
//     std::cin>>in;
//     if(in == "y")done = true;

// }


//TESTS
// vector<int> tst = {8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9};
// //vector<int> tst = {1,2,3,4,5,6,7,15,8,32};
// Tree* tree = new Tree(tst);
    
// tree->printTree(tree->getRoot());
// // tree->search(3);
// tree->search(8);
// tree->search(1);
// tree->search(1000);

// tree->insert(75);
// tree->insert(11);
// tree->printTree(tree->getRoot());

// std::cout<<"\n\nDELETING NODES\n";
// tree->deleteNode(4);
// std::cout<<"\n\nREPRINT NEW TREE\n";
// tree->printTree(tree->getRoot());

// int input = 0;
// bool done = false;
// while(!done){
//     std::cout<<"number to delete?: ";
//     std::cin >> input;
//     tree->deleteNode(input);
//     tree->printTree(tree->getRoot());

//     std::string in;
//     std::cout<<"done?: ";
//     std::cin>>in;
//     if(in == "y")done = true;

// }