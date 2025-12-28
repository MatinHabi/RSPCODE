#ifndef GRAPH_H
#define GRAPH_H
#include <unordered_map>
#include <vector>
#include <queue>
#include <unordered_set>
#include <iostream>

/*
Time Complexityies:
    -insert: 
        Average O(1) [.find() .insert() have O(1)] -> can become O(n) with one node pointing to too many vals
    -delete:
        Average O(1) [.erase() is O(1)] -> can become O(n) with too many vals
    -BFS: O(V+E)
    -DFS: O(V+E) -> V = num of verticies & E = num of nodes

*/

class Graph{
private:
    std::unordered_map<int, std::unordered_set<int>> adj;
    
    bool DFSRec(int start, int v, std::unordered_set<int> &visited){
        if(start == v){
            return true;
        }else{
            for(int i : adj[start]){ //start by looking at the child nodes
                if(visited.find(i) == visited.end()){ //if it hasn't been visited
                    visited.insert(i); //visit it
                    if(DFSRec(i,v,visited))return true; //return out of the loop
                }
            }
        }
        return false;//not found
    } 
public:
    bool isDirected;
    Graph(int verticies, bool d = false): adj(verticies), isDirected(d){}

    void addEdge(int v, int u){ //Average Time complexity to insert n elements : O(n) [T.C. for inserting 1 element O(1)]
        //trying to add node (3, 1) -> the node is 3 it is connected to 1
           auto &setV = adj[v];
           if(isDirected){
            if(adj.find(u) != adj.end()){//the node v is pointing to exists
                auto& setU = adj[u]; //get its set and check whether it is already pointing to v
                    if(setU.find(v) != setU.end()){ //if it finds that u does point to v
                        std::cout << u << " already points to " << v << " - cannot point back in a directed graph\n";
                        return;
                    }
                }
            }
            //cannot point to iself
            if(u == v){std::cout<<"cannot point to itself!\n";return;}
            //add u if it isn't already a node
            if(adj.find(u) == adj.end()){adj[u];}
            //cant add the same node twice   
            std::cout << (setV.insert(u).second ? "" : std::to_string(u) + " already exists in " + std::to_string(v));
    }

    void deleteNode(int n){
        auto rem = adj.find(n);
        if(rem == adj.end()){ //does n even exist
            std::cout<<"Already removed or Does not exists\n";
            return;
        }
        for(auto& i : adj){ //remove all connections to n MAKE SURE TO USE REFERENCES
            i.second.erase(n);
        }
        //remove n
        adj.erase(n);
    }

    void printGraph(){
        std::cout<< (isDirected ? "\nDirected Graph\n" : "\nUndirected Graph\n");
        for(auto &row: adj){
            std::cout<< row.first << ": ";
            for(auto n: row.second){
                std::cout << n << " ";
            }
            std::cout<<"\n";
        }
    }

    void BFS(int startNode, int v){ // v is what we're searching for and start = startNode
        //obvious case: start node == v OR graph is empty OR Node is not in Graph
        if(adj.find(startNode) == adj.end()) {std::cout << "Start node not found in graph!\n";return;}
        if(startNode == v){std::cout<<"Target = startNode!\n";return;}
        //USE WHILE LOOP
        std::queue<int> q;
        std::unordered_set<int>visited;
        //BFS goes down 1 level(child nodes)->searches to see if v is there->goes down another level

        q.push(startNode);
        visited.insert(startNode);

        while (!q.empty()){
            int curr = q.front();
            q.pop();

            for(int i : adj[curr]){
                if(visited.find(i) == visited.end()){//ensures you're not visiting same node twice
                    if(i == v){std::cout << "Found-BFS!\n";return;}
                    visited.insert(i); //you're visiting the nodes by looking at them
                    q.push(i);
                }
            }
        }
        std::cout<<"Not found-BFS\n";

    }   

    void DFS(int start, int v){
        //USE RECURSION
        std::unordered_set<int> visited;
        visited.insert(start);

        std::cout << (DFSRec(start,v,visited) ? "Found-DFS!\n" : "Not found-DFS\n");
    }

};

#endif