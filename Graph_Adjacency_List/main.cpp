#include <iostream>
using namespace std;
#include "graph.h"

int main(){
    vector<vector<int>> x 
    = {{1,2},{2,4},{1,3},{3,2}};
    Graph *g = new Graph(4, true);
    for(auto i : x){
        g->addEdge(i[0], i[1]);
    }
    //g->addEdge(1,2);
    // g->addEdge(2,3);
    // g->addEdge(1,3);
    g->printGraph();
    // g->BFS(1,9);
    // g->DFS(1,9);
    g->deleteNode(2);
    g->printGraph();


}