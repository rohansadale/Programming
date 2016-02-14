/*
Recursive Approach

Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins, 
how many ways can we make the change? The order of coins doesn’t matter.

For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4. 
For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int combinations(vector<int>&v, int m, int n){
    if(n == 0)
        return 1;
    if (n < 0)
        return 0;
    if(m <= 0 && n >= 1)
        return 0;
    return combinations(v, m-1, n) + combinations(v, m, n-v[m-1]);
}

int main()
{
    vector<int> v = {1,2,3};
    int n = 5;
    cout << combinations(v,v.size(), n);
    
}

// Output - 5
