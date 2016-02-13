// Graph creation using structures

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct node{
    int data;
    node*next;
};

struct adjList{
    node *head;
};

struct graph{
    int v;
    adjList *array;
};

graph* createGraph(int V){
    graph *g = new graph;
    g->v = V;
    g->array = new adjList[V];
    
    for(int i = 0; i < V; i++)
        g->array[i].head = NULL;
        
    return g;
}

void addEdge(graph *g, int src, int dest){
    node *n = new node;
    n->data = dest;
    n->next = g->array[src].head;
    g->array[src].head = n;
    
    
    // For undirected Graph
    n = new node;
    n->data = src;
    n->next = g->array[dest].head;
    g->array[dest].head = n;
}

void printGraph(graph *g){
    for(int i = 0; i < g->v; i++){
        cout << i << " -> ";
        while(g->array[i].head){
            cout << g->array[i].head->data << " -> ";
            g->array[i].head = g->array[i].head->next;
        }
        cout << "NULL" << endl;
    }
}

int main()
{
    graph *g = createGraph(4);
    addEdge(g,0,1);
    addEdge(g,0,2);
    addEdge(g,1,3);
    printGraph(g);
}

/*
Output
0 -> 2 -> 1 -> NULL
1 -> 3 -> 0 -> NULL
2 -> 0 -> NULL
3 -> 1 -> NULL
*/