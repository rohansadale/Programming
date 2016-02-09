/*
Given an array of numbers, arrange them in a way that yields the largest value. 
For example, if the given numbers are {54, 546, 548, 60}, the arrangement 6054854654 gives the largest value. 
And if the given numbers are {1, 34, 3, 98, 9, 76, 45, 4}, then the arrangement 998764543431 gives the largest value.
*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool myCompare(int X, int Y){
    string XY = to_string(X) + to_string(Y);
    string YX = to_string(Y) + to_string(X);
    
    return XY > YX ? 1 : 0;
}

long largestNumber(vector<int> &v){
    sort(v.begin(), v.end(), myCompare);
    
    string largestNo = "";
    for(int i = 0; i < v.size(); i++)
        largestNo.append(to_string(v[i]));
    
    return stol(largestNo);
    
}

main(){
    vector<int> v =  {54, 546, 548, 60};
    cout << largestNumber(v);
    
}

// Output - 6054854654
