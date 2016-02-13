// Detect whether cycle is present in Graph

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
        bool isCyclic();
        bool isCyclicUtil(int, vector<bool>&, vector<bool>&);
        ~Graph();
};

Graph::Graph(int v){
    this->v = v;
    adjList = new list<int>[v];
}

Graph::~Graph(){
    delete []adjList;
}

void Graph::addEdge(int src, int dest){
    adjList[src].push_back(dest);
    
    // Commenting out for making Directed Graph
    //adjList[dest].push_back(src);
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

bool Graph::isCyclicUtil(int n, vector<bool> &visited, vector<bool> &stacked){

    if(visited[n] == false){
        visited[n] = true;
        stacked[n] = true;
        
        for(auto it_l = adjList[n].begin(); it_l != adjList[n].end(); it_l++){
            if(!visited[*it_l] && isCyclicUtil(*it_l, visited, stacked))
                return true;
            else if(stacked[*it_l])
                return true;
        }
    }
    stacked[n] = false;
    return false;
}

bool Graph::isCyclic(){
    vector<bool> visited(v,false);
    vector<bool> stacked(v,false);
    
    for(int i = 0; i < v; i++){
        if(isCyclicUtil(i, visited, stacked)){
            return true;
        }
    }
    return false;
}


int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    
    cout << "Graph - \n";
    g.printGraph();
    
    cout << "\nIs cycle present - ";
    cout << (g.isCyclic() ? "Yes" : "No");
    
    
}

/*

Output
Graph - 
0->1->2->null
1->2->null
2->0->3->null
3->3->null

Is cycle present - Yes

*/