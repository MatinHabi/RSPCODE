#ifndef TESTER_H
#define TESTER_H

#include "tree.h"
#include <chrono>
#include <vector>
#include <iostream>
#include <fstream>

class Tester {
private:
    std::vector<int> list;
    Tree test;
    static constexpr int ITER = 100000; //constexpr is value that is only known at compile time -> not stored in RAM
                                        // can be directly used in code

public:
    Tester(): list{ 50,
                    25, 75,
                    12, 37, 62, 87,
                    6, 18, 31, 43, 56, 68, 81, 93,
                    3, 9, 15, 21, 28, 34, 40, 46, 53, 59, 65, 71, 78, 84, 90, 96,
                    1, 4, 7, 10, 13, 16, 19, 22, 26, 29, 32, 35, 38, 41, 44, 47,
                    52, 55, 58, 61, 64, 67, 70, 73, 79, 82, 85, 88, 91, 94, 97, 99,
                    2, 5, 8, 11, 14, 17, 20, 23, 27, 30, 33, 36, 39, 42, 45, 48,
                    51, 54, 57, 60, 63, 66, 69, 72, 74, 76, 77, 80, 83, 86, 89, 92, 95, 98, 100},test(list){}
    

    void printList(){
        test.printTree(test.getRoot());
    }

    void duration_diff_BST_linSearch(int v) {
        using clock = std::chrono::steady_clock;

        volatile int sink = 0; //volatile tells the compiler "DONT FW THIS VALUE MF" so it don't touch it

        // Linear search
        auto start1 = clock::now();
        for (int k = 0; k < ITER; ++k) {
            for (int value : list) {
                if (value == v) {
                    sink = value;
                    break;
                }
            }
        }
        auto end1 = clock::now();

        // BST search
        auto start2 = clock::now();
        for (int k = 0; k < ITER; ++k) {
            Node* found = test.search2(v);
            if (found) sink = found->data;
        }
        auto end2 = clock::now();

        auto linear_ms =
            std::chrono::duration<double, std::milli>(end1 - start1).count();
        auto bst_ms =
            std::chrono::duration<double, std::milli>(end2 - start2).count();

        std::cout << "Linear search total: " << linear_ms << " ms ("
                  << linear_ms / ITER << " ms per search)\n";

        std::cout << "BST search total:    " << bst_ms << " ms ("
                  << bst_ms / ITER << " ms per search)\n";
    }
};

#endif
