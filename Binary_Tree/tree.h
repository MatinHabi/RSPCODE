#ifndef TREE_H
#define TREE_H
#include <vector> 
#include "node.h"


class Tree{
private:
    Node* root;

        Node* deleteNodeRec(Node* node, int value){
        if(!node)return nullptr;
        if(value < node->data){
            node->left = deleteNodeRec(node->left, value);
        }else if(value > node->data){
            node->right = deleteNodeRec(node->right, value);
        }else{
            //case 1: node has no children
            if(!node->left && !node->right){
                delete node;
                return nullptr;
            }
            //case 2: no left child
            if(!node->left){
                Node*child = node->right;
                delete node;
                return child;
            }
            //case 3: no right child
            if(!node->right){
                Node*child = node->left;
                delete node;
                return child;
            }
            //case 4 has both children
            if(node->left && node->right){
                //using inoder succession (copying the value of the smallest leaf node from the right sub-tree and then deleting that leaf node)
                Node*succ=node->right;
                while(succ->left)succ = succ->left;

                node->data = succ->data;
                node->right = deleteNodeRec(node->right, succ->data);
                
            }
            
        }

        return node;
    }

    Node* searchRec(Node*curr,int val){
        if(!curr)return nullptr;
        else{
            if(val < curr->data){
                return searchRec(curr->left, val);
            }else if(val > curr->data){
                return searchRec(curr->right, val);
            }else{
                return curr;
            }
        }
        return nullptr;
    }

public:
    Tree(std::vector<int> x): root(nullptr){
        for(int i : x){
            insert(i);
        }
    }
    void insert(int v){ //UPDATE CAN BE DONE WITH INSERT
        if(root==nullptr){root = new Node(v);return;}
        Node* curr = root;
        while(true){
            if(v < curr->data){
                if(curr->left == nullptr){curr->left = new Node(v);break;}
                curr = curr->left;
            }
            if(v > curr->data){
                if(curr->right == nullptr){curr->right = new Node(v);break;}
                curr = curr->right;
            }
            if(v == curr->data){
                std::cerr << "Value " << v << " can't match previous nodes!\n";break;
            }
        }
    }
    Node* getRoot(){return root;}
    
    void printTree(Node* node, int depth = 0, bool isLeft = false) {
        if (node == nullptr) {
            for (int i = 0; i < depth; i++) std::cout << "     ";
            std::cout << (isLeft ? " \\-- " : " /-- ");
            std::cout << "NULL\n";
            return;
        }

        // Print right subtree first
        printTree(node->right, depth + 1, false);

        // Indent to correct depth
        for (int i = 0; i < depth; i++) std::cout << "     ";

        // Print branch indicator
        if (depth > 0) {
            std::cout << (isLeft ? " \\-- " : " /-- ");
        }

        // Print node value
        std::cout << node->data << "\n";

        // Print left subtree
        printTree(node->left, depth + 1, true);
    }

    bool search(int v){
        bool res;
        searchRec(root,v) ? res = true : res = false;
        std::cout<< (res ? "found!\n" : "not found!\n"); 
        return res;
    }

    Node* search2(int v){
        return searchRec(root,v);
    }

    void deleteNode(int v){
        root = deleteNodeRec(root,v);
    }


};


#endif //TREE_H