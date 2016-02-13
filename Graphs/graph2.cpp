// Graph implementation using class based approach

#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

class Graph{
        int v;
        list<int> *adjList;
    public:
        Graph(int);
        void addEdge(int, int);
        void printGraph();
        ~Graph();
};

Graph::Graph(int v){
    this->v = v;
    adjList = new list<int>[v];
}

void Graph::addEdge(int src, int dest){
    adjList[src].push_back(dest);
    adjList[dest].push_back(src);
}

void Graph::printGraph(){
    for(int i = 0; i < v; i++){
        list<int>::iterator it_l;
        cout << i << "->";
        for(it_l = adjList[i].begin(); it_l != adjList[i].end(); it_l++){
            cout << *it_l << "->";
        }
        cout << "null" << endl;
    }
}

Graph::~Graph(){
    delete []adjList;
}

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    
    g.printGraph();
}

/*
Output
0->1->4->null
1->0->2->3->4->null
2->1->3->null
3->1->2->4->null
4->0->1->3->null
*/