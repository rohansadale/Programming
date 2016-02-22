/*
A child is running up a staircase with n steps, and can hop either 1 step, 2 steps, or
3 steps at a time. Implement a method to count how many possible ways the child
can run up the stairs.
*/

#include<iostream>
#include<vector>
using namespace std;

int reachSteps(int n){
    vector<int>v(n+1);
    v[0] = 0;
    v[1] = 1;
    v[2] = 2;
    v[3] = 4;
    for(int i = 4; i <= n; i++){
        v[i] = v[i-3] + v[i-2] + v[i-1];
        //cout << v[i];
    }
    return v[n];
}

main(){
    cout << reachSteps(4);
}
