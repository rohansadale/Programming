//Given an integer array, output all pairs that sum up to a specific value k

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void pairs(vector<int> &v, int k){
    if(v.empty())
        return;
        
    map<int,int> m;
    for(int i = 0; i < v.size(); i++)
        m[v[i]] = 0;
    
    for(int i = 0; i < v.size(); i++){
        if( !m[v[i]] && m.find(k - v[i]) != m.end()){
            m[k - v[i]] = 1;
            m[v[i]] = 1;
            cout << v[i] << " " << k-v[i] << endl;
        }
    }
}

main()
{
    vector<int>v = {3,6,5,4,2};
    int k = 9;
    pairs(v, k);
}


/*
Output
3 6
5 4
*/
