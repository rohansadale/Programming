// Given an index k, return the kth row of the Pascal's triangle.

#include<iostream>
#include<vector>
using namespace std;

void pascalTriangle(int n){
    if (n < 1)
        return;
        
    vector<int>row(1,1);
    
    for(int i = 2; i <= n; i++){
        int prev = 1;
        for(int j = 1; j < i-1; j++){
            int temp = row[j];
            row[j] += prev;
            prev = temp;
        }
        row.push_back(1);
    }
    
    for(int i = 0; i < row.size(); i++){
            cout << row[i];
    }
}

int main()
{
    int n = 5;
    pascalTriangle(n);
}


// Output - 14646
