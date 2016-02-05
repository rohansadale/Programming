// Given an array of integers (positive and negative) find the largest continuous sum.

#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

int continuousSum(vector<int> &v){
    int max = -30000;
    int sum = 0;
    for(int i = 0; i < v.size(); i++){
        sum += v[i];
        max = max > sum ? max : sum;
    }
    return max;
}

main()
{
    vector<int> v = {-1,-3,-4,-6,-3,-12,-4,-6,-2};
    cout<<continuousSum(v);

}

// Output = -1
