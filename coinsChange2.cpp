/*
Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins, 
how many ways can we make the change? The order of coins doesn’t matter.

For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4. 
For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{
    vector<int> v = {1,2,3};
    int n = 10;
    vector<int>counts(n+1,0);
    
    counts[0] = 1;
    for(int i = 0; i < v.size(); i++){
        for(int j = v[i]; j <= n; j++){
            counts[j] += counts[j-v[i]];
        }
    }
    cout << counts[n];
    
}

// Output - 14
