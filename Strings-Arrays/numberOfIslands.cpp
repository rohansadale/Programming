/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. 
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3
*/

class Solution {
public:
    void island(vector<vector<char> > &grid,  vector<vector<bool> > &path, int row, int col, int i, int j){
        path[i][j] = false;
        
        if(i < row-1 && grid[i+1][j] == '1' && path[i+1][j] == true)
            island(grid, path, row, col, i+1, j);
        if(j < col-1 && grid[i][j+1] == '1' && path[i][j+1] == true)
            island(grid, path, row, col, i, j+1);
        if(i > 0 && grid[i-1][j] == '1' && path[i-1][j] == true)
            island(grid, path, row, col, i-1, j);
        if(j > 0 && grid[i][j-1] == '1' && path[i][j-1] == true)
            island(grid, path, row, col, i, j-1);
    }
    
    int numIslands(vector<vector<char> >& grid) {
        int row = grid.size();
        int col = row>0 ? grid[0].size() : 0;
        int count = 0;
        vector<vector<bool> > path(row, vector<bool>(col, true));
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                    if(grid[i][j] == '1' && path[i][j] == true){
                        island(grid, path, row, col, i, j);
                        count++;
                    }
            }
        }
        return count;
    }
};
