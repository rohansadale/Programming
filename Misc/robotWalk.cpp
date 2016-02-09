/*
Imagine a robot sitting on the upper left comer of an X by Ygrid. The robot can only
move in two directions: right and down. How many possible paths are there for the
robot to go from (0, 0) to (X, Y) ?
*/


#include<iostream>
#include<vector>
using namespace std;

int possiblePaths(int X, int Y){
    int M[X][Y];
    
    for(int i = 0; i < X; i++)
        M[i][0] = 1;
    
    for(int i = 0; i < Y; i++)
        M[0][i] = 1;
        
    for(int i = 1; i < X; i++){
        for(int j = 1; j < Y; j++){
            M[i][j] = M[i-1][j] + M[i][j-1];
        }
    }
    
    return M[X-1][Y-1];
}


main(){
    cout << possiblePaths(3,4);
}

//Output - 10
