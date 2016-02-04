// Write a method to return all subsets of a set.

#include <math.h>
#include<iostream>
#include <vector>
using namespace std;

void powerSet(vector<int> &v){
    if(v.empty()){
        cout << "Null Set";
        return;
    }
        
    int set_size = pow(2, v.size());
    for(int i = 0; i < set_size; i++){
        for(int j = 0; j < v.size(); j++){
            if(i & 1<<j)
                cout << v[j];
        }
        cout << endl;
    }
}

main()
{
    vector<int> v  = {1,2,3};
    powerSet(v);
}

/*
Output:

1
2
12
3
13
23
123
*/
