#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int endRow = mat.size();
        int endCol = mat[0].size();
        int inputRow = 0;
        int inputCol = 0;

        if(r*c != endRow * endCol)
            return mat;
        vector<vector<int>> result (r, vector<int>(c));
        for(int row = 0; row < endRow; row++ ){
            for (int col = 0; col< endCol; col ++){
                
                result[inputRow][inputCol] = mat[row][col];
                inputCol ++;
                if (inputCol == c){
                    inputCol =0;
                    inputRow ++;
                }
            }
        }
        return result;
        
    }

int main(){
    vector<vector<int>> mat = {{1,2},{3,4}};
    vector<vector<int>> result = matrixReshape(mat, 1,4);
    for(int i = 0; i< result.size(); i++){
        for (int j =0; j< result[0].size(); j ++)
            cout<<result[i][j];
        cout<<"\n";
    }
}