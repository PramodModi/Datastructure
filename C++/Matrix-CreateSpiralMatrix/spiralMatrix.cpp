/*
Given a positive integer n, generate an n x n matrix filled with elements 
from 1 to n^2 in spiral order.
Example1:
    Input: n = 3
    Output: [[1,2,3],[8,9,4],[7,6,5]]

Example 2:
    Input: n = 1
    Output: [[1]]

Constraints:
    1 <= n <= 20
*/

# include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> createSpiralMatrix(int n){

    vector<int> list(n*n +1);
    for(int i = 1; i<= n*n; i++){
        list[i-1] = i;
    }

    vector<vector<int>> matrix(n, vector<int>(n)); 

    int startRow = 0;
    int endRow = n-1;
    int startCol = 0;
    int endCol = n-1;
    int index = 0;
    while(startRow <= endRow and startCol <= endCol){
        for(int col = startCol; col <= endCol; col++){
            matrix[startRow][col] = list[index++];
        }
        for(int row = startRow +1; row<= endRow; row++){
            matrix[row][endCol] = list[index++];
        }

        for(int col = endCol-1; col >= startCol; col--){
            matrix[endRow][col] = list[index++];
        }
        for(int row = endRow -1; row > startRow; row --){
            matrix[row][startCol] = list[index ++];
        }
        if(index == list.size())
            break;
        startRow ++;
        endRow --;
        startCol ++;
        endCol --;
    }

    return matrix;

}

int main(){

    vector<vector<int>> matrix = createSpiralMatrix(3);
    for(int i =0; i< matrix.size(); i++){
        for(int j =0; j<matrix[0].size(); j++){
            cout<<matrix[i][j];
        }
        cout<<"\n";
    }
    return 1;
}