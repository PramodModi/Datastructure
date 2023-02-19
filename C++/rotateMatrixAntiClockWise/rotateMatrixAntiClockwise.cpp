/*
Problem:Rotate matrix in Anticlock wise by 90 degree
Approach:
First reverse the value of each cell in a row wise. 
That means if row1 = [3,6,9] then after reverse it should be [9,6,3]. 
Second, transpose the matrix that means, row should be column.

Example:

    [3,6,9]
    [2,5,8]
    [1,4,7]
Step1 : Reverse each row.

    [9,6,3]
    [8,5,2]
    [7,4,1]
step2: Transpose matrix. swap the values from diagonally. 
Means row should be column.

    [9,8,7]
    [6,5,4]
    [3,2,1]
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
    reverseColumns(matrix);
    transposeMatrix(matrix);
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