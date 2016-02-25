/*
Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. 
You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Return 4
The longest increasing path is [1, 2, 6, 9].

Example 2:

nums = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
Return 4
The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

*/

class Solution {
public:
    int longest(vector<vector<int>>& matrix, vector<vector<int>>& path, int row, int col, int i, int j){
        if(path[i][j] > 0)
            return path[i][j];
        
        int temp = matrix[i][j];
        //matrix[i][j] = INT_MIN;
        int maxL = 0;
        
        if(i < row-1 && temp < matrix[i+1][j])
            maxL = max(maxL, longest(matrix, path, row, col, i+1, j));
        if(j < col-1 && temp < matrix[i][j+1])
            maxL = max(maxL, longest(matrix, path, row, col, i, j+1));
        if(i > 0 && temp < matrix[i-1][j])
            maxL = max(maxL, longest(matrix, path, row, col, i-1, j));
        if(j > 0 && temp < matrix[i][j-1])
            maxL = max(maxL, longest(matrix, path, row, col, i, j-1));
            
        matrix[i][j] = temp;
        path[i][j] = maxL + 1;
        return path[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = row > 0 ? matrix[0].size() : 0;
        int maxL = 0;
        vector<vector<int> > path(row, vector<int>(col, 0));
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                maxL = max(maxL, longest(matrix, path, row, col, i, j));
            }
        }
        return maxL;
    }
};
