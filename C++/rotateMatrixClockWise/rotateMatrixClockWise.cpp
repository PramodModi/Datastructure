/*
Problem:Rotate matrix in Clock wise by 90 degree
Approach:
First, transpose the matrix that means, row should be column.
Second, reverse the value of each cell in a row wise.  


Example:

    [3,6,9]
    [2,5,8]
    [1,4,7]
Step1 : Transpose the matrix.

    [3,2,1]
    [6,5,4]
    [9,8,7]
step2: Reverse each row

    [1,2,3]
    [4,5,6]
    [7,8,9]
This is the output.
*/

# include <iostream>
# include <vector>

using namespace std;


void reverseList(vector<int> & column){
    int l =0;
    int r = column.size() -1;

    while (l < r){
        int temp = column[l];
        column[l] = column[r];
        column[r] = temp;
        l += 1;
        r -= 1;
    }
}

void reverseColumns(vector<vector<int>> & matrix){
    for(int r = 0; r < matrix.size(); r ++){
        reverseList(matrix[r]);
    }
}

void transposeMatrix(vector<vector<int>> & matrix){

    for(int i = 0; i< matrix.size(); i++){
        for(int j = i; j< matrix[0].size(); j++){
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}


vector<vector<int>> rotateMatrix(vector<vector<int>> & matrix){
    transposeMatrix(matrix);
    reverseColumns(matrix);
    return matrix;
}

int main(){
    
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    rotateMatrix(matrix);
    for(int i =0; i<matrix.size(); i++){
        for(int j = 0; j<matrix[0].size(); j++)
            cout<<matrix[i][j];
        cout<<"\n";
    }
    return 1;
}