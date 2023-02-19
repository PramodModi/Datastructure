/*
Problem: 
You are given an integer matrix isWater of size m x n that represents a map 
of land and water cells.

If isWater[i][j] == 0, cell (i, j) is a land cell.
If isWater[i][j] == 1, cell (i, j) is a water cell.
You must assign each cell a height in a way that follows these rules:

The height of each cell must be non-negative.
If the cell is a water cell, its height must be 0.
Any two adjacent cells must have an absolute height difference of at most 1. 
A cell is adjacent to another cell if the former is directly north, east, south, 
or west of the latter (i.e., their sides are touching).
Find an assignment of heights such that the maximum height in the matrix is 
maximized.

Return an integer matrix height of size m x n where 
height[i][j] is cell (i, j)'s height. 
If there are multiple solutions, return any of them.
*/

#import <iostream>
#import<vector>
#import <queue>

using namespace std;

vector<pair<int,int>> getNeighbours(int r,int c, vector<vector<int>> matrix){
    vector<pair<int, int>> nbrs;
    if(r>0){
        nbrs.push_back({r-1, c});
    }
    if(r< matrix.size()-1){
        nbrs.push_back({r+1, c});
    }
    if(c > 0){
        nbrs.push_back({r, c-1});
    }
    if(c < matrix[0].size()-1){
        nbrs.push_back({r, c+1});
    }
    return nbrs;
}

vector<vector<int>> heighestPeak(vector<vector<int>> & matrix){
    queue <pair<int, int> > temp;
    for(int i =0; i < matrix.size(); i++){
        for(int j = 0; j< matrix[0].size(); j++){
            if (matrix[i][j] == 1)
                matrix[i][j] = 0;

            else
                matrix[i][j] = -1;

            if (matrix[i][j] == 0){
                temp.push({i,j});
            }
        }
    }

    while(!temp.empty()){
        auto it = temp.front();
        temp.pop();
        int r = it.first;
        int c = it.second;
        int h = matrix[r][c];

        auto neighbours = getNeighbours(r,c,matrix);

        for (auto nbr : neighbours){
            int row = nbr.first;
            int col = nbr.second;
            if(matrix[row][col] == -1){
                matrix[row][col] = h+1;
                temp.push({row, col});
            }
        }

    }
    return matrix;
}

int main(){

    vector<vector<int>> matrix = {{0,1}, {0,0}};
    heighestPeak(matrix);
    for(int i =0; i< matrix.size(); i++){
        for(int j =0; j< matrix[0].size(); j++){
            cout<<matrix[i][j];
        }
        cout<<"\n";
    }
}
