/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"
*/

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows < 2)
            return s;
        int n = s.size();
        string result;
        
        for(int i = 0; i < numRows; i++){
            int j = i;
            bool flip = true;
            while(j < n){
                int step;
                if(flip){
                    step = 2*numRows - 2 - 2*i;
                }    
                else
                    step = 2*i;
                
                if(i == 0 || i == numRows -1)
                    step = 2*numRows - 2;
                flip = !flip;
                result.push_back(s[j]);
                
                cout << s[j] << " " << step <<  endl;
                j += step;
            }
        }
        
        return result;
    }
};
