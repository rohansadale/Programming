// Matrix rotation by 90 degrees and in-place

/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?

*/


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int row = matrix.size();
        int col = row > 0 ? matrix[0].size() : 0; 
        
        for(int i = 0; i < row/2; i++){
            for(int j = 0; j < ceil(col/2.0); j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[row-j-1][i];
                matrix[row-j-1][i] = matrix[row-i-1][col-j-1];
                matrix[row-i-1][col-j-1] = matrix[j][col-i-1];
                matrix[j][col-i-1] = temp;
            }
        }
    }
};
