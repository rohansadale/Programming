// Given numRows, generate the first numRows of Pascal's triangle.


#include<iostream>
#include<vector>
using namespace std;

void pascalTriangle(int n){
    if (n < 1)
        return;
        
    vector<vector<int> > res;
    vector<int>row(1,1);
    res.push_back(row);
    
    for(int i = 2; i <= n; i++){
        int prev = 1;
        for(int j = 1; j < i-1; j++){
            int temp = row[j];
            row[j] += prev;
            prev = temp;
        }
        row.push_back(1);
        res.push_back(row);
    }
    
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++)
            cout << res[i][j];
        cout << endl;
    }
}

int main()
{
    int n = 5;
    pascalTriangle(n);
}

/*
Output
1
11
121
1331
14641
*/
