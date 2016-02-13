// DisjointSet implementation
// Used to detect cycle in undirected Graph
// https://www.youtube.com/watch?v=UBY4sF86KEY

#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class disjointSet{
    unordered_map<int, int> parent;
    public:
        disjointSet(int n){
            for(int i = 0; i < n; i++)
                parent[i] = i;
        }
        
        int find(int);
        void unionSet(int, int);
};

int disjointSet::find(int n){
    if(parent[n] == n)
        return n;
    else
        find(parent[n]);
}

void disjointSet::unionSet(int n1, int n2){
    parent[n1] = n2;
}

int main()
{
   disjointSet d(5);
   cout << d.find(1) << endl;
   d.unionSet(1,2);
   cout << d.find(1) << endl;
}

/*
Output
1
2
*/