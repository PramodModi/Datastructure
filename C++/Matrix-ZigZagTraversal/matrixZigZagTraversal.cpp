/*
Write a function that takes in an n x m two-dimensional array 
(that can be square-shaped when n == m) and returns a one-dimensional array 
of all the array's elements in zigzag order. 
Zigzag order starts at the top left corner of the two-dimensional array, 
goes down by one element, and proceeds in a zigzag pattern all the way 
to the bottom right corner.

Example:

array =

[
 [1, 3, 4, 10],
 [2, 5, 9, 11],
 [6, 8, 12, 15],
 [7, 13, 14, 16],
]
Output:

[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16]
*/

# include<iostream>
#include<vector>
using namespace std;

vector<int> zigzagTraversal(vector<vector<int>> matrix){
    vector<int> result;
    bool goingDown = true;
    int endRow = matrix.size()-1;
    int endCol = matrix[0].size()-1;
    int r =0;
    int c = 0;
    while (r<=endRow && c<= endCol && r>= 0 && c>=0){
        result.push_back(matrix[r][c]);
        if(goingDown){
            if(c == 0 || r == endRow){
                goingDown = false;
                if(r == endRow){
                    c++;
                }
                else{
                    r ++;
                }
            }
            else{
                r ++;
                c --;
            }
        }
        else{
            if(r == 0 || c == endCol){
                goingDown = true;
                if(c == endCol){
                    r ++;
                }
                else{
                    c ++;
                }
            }
            else{
                r --;
                c ++;
            }
        }
    }
    return result;
}

int main(){
    vector<vector<int>>  matrix ={{1, 3, 4, 10},{2, 5, 9, 11},{6, 8, 12, 15},{7, 13, 14, 16}};
    vector<int> result = zigzagTraversal(matrix);
    for (int i : result){
        cout<<i<<" ";
    }
}