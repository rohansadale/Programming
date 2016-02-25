// Matrix Rotation (n*n) by 90 degrees

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int row = matrix.size();
        int col = row > 0 ? matrix[0].size() : 0; 
        
        vector<vector<int> > m (col, vector<int>(row,0));
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                cout << matrix[i][j] << endl;
                m[j][col-i-1] = matrix[i][j];
            }
        }
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++)
                matrix[i][j] = m[i][j];
        }
    }
};
