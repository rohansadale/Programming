/*
Given a sorted array of n integers that has been rotated an unknown number of
times, write code to find an element in the array. You may assume that the array was
originally sorted in increasing order.
*/

#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

int rotatedPosition(vector<int> &v){
    int low = 0;
    int high = v.size()-1;
    
    while(low < high){
        int mid = (low+high)/2;
        if(v[mid] > v[high])
            low = mid;
        else
            high = mid;
        
        if(abs(low-high) == 1)
            break;
    }
    
    return v[low]<v[high]? low : high;
}

main()
{
    vector<int>v = {3,4,5,1,2};
    cout << rotatedPosition(v) << " " << v[rotatedPosition(v)];
}


// Output - 4 1
