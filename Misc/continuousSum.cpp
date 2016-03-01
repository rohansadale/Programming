// Given an array of integers (positive and negative) find the largest continuous sum.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int continuousSum(vector<int> &v){
    int sum = v[0];
    int maxSum = v[0];
    
    for(int i = 1; i < v.size(); i++){
        sum = max(v[i], sum+v[i]);
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

main()
{
    vector<int> v = {-2, -3, 4, -1, -2, -3, 8, -3};
    cout<<continuousSum(v);

}

// Output = 8
