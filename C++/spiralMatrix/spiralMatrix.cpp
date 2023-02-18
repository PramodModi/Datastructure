#include <iostream>
#include <vector>

using namespace std;

vector<int> getSpiralMatrix(vector<vector<int>> & matrix){
    int startRow = 0;
    int endRow = matrix.size()-1;
    int startCol = 0;
    int endCol = matrix[0].size()-1;

    vector<int> result;

    while(startRow <= endRow && startCol <= endCol){
        for (int col =startCol; col <= endCol; col ++){
            result.push_back(matrix[startRow][col]);
        }
        for (int row = startRow +1; row <= endRow; row++){
            result.push_back(matrix[row][endCol]);
        }

        for (int col = endCol -1;col >= startCol; col--){
            if (startRow == endRow)
                break;
            result.push_back(matrix[endRow][col]);
        }
        for (int row = endRow - 1; row >= startRow +1; row --){
            if(endCol == startCol)
                break;
            result.push_back(matrix[row][startCol]);
        }
        startRow ++;
        endRow --;
        startCol  ++;
        endCol --;
    }
    return result;


}

int main(){

    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
     
    vector<int> result = getSpiralMatrix(matrix);

    for(auto i : result)
        cout<<i;
    return 1;
}
