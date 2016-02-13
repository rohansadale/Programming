// Breadth First and Depth First Graph Traversal

#include <iostream>
#include <algorithm>
#include <list>
#include <queue>
using namespace std;

class Graph{
        int v;
        list<int> *adjList;
    public:
        Graph(int);
        void addEdge(int, int);
        void printGraph();
        void BFS(int);
        void DFS(int);
        void DFSUtil(int, vector<bool>&);
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

void Graph::BFS(int n){
    queue<int> q;
    vector<bool>visited(v, false);
    
    q.push(n);
    visited[n] = true; 
    while(!q.empty()){
        int vertex = q.front();
        cout << vertex << endl;
        q.pop();
        list<int>::iterator it_l;
        for(it_l = adjList[vertex].begin(); it_l != adjList[vertex].end(); it_l++){
            if(!visited[*it_l]){
                visited[*it_l] = true;
                q.push(*it_l);  
            }
        }
    }
}

void Graph:: DFSUtil(int n, vector<bool> &visited){
    cout << n << endl;
    list<int>::iterator it_l;
    for(it_l = adjList[n].begin(); it_l != adjList[n].end(); it_l++){
        if(!visited[*it_l]){
            visited[*it_l] = true;
            DFSUtil(*it_l, visited);
        }
    }
}

void Graph::DFS(int n){
    vector<bool>visited(n, false);
    visited[n] = true;
    DFSUtil(n, visited);
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
    
    cout << "Adjacency List - \n";
    g.printGraph();
    
    cout << "\nBFS - \n";
    g.BFS(0);
    
    cout << "\nDFS - \n";
    g.DFS(0);    
}

/*
Output - 

Adjacency List - 
0->1->4->null
1->0->2->3->4->null
2->1->3->null
3->1->2->4->null
4->0->1->3->null

BFS - 
0
1
4
2
3

DFS - 
0
1
2
3
4

*/