/*
Write a function that takes in a list of Cartesian coordinates 
(i.e., (x, y) coordinates) and returns the number of rectangles formed by these 
coordinates. A rectangle must have its four corners amongst the coordinates 
in order to be counted, and we only care about rectangles with sides parallel to 
the x and y axes (i.e., with horizontal and vertical sides--no diagonal sides). 
You can also assume that no coordinate will be farther than 100 units from the 
origin.
*/

#include <iostream>
#include<unordered_map>
#include <vector>
#include <string>

using namespace std;

string getKey(int x, int y){
    return to_string(x) + "-" + to_string(y);
}
int rectangleCount(vector<vector<int>> coord){
    unordered_map<string, bool> temp;
    int count = 0;
    for (auto c : coord ){
        int x = c[0];
        int y = c[1];
        string key = getKey(x,y);
        temp[key] = true;
    }

    for (auto c1: coord){
        int x1 = c1[0];
        int y1 = c1[1];
        for (auto c2 : coord){
            
            int x2 = c2[0];
            int y2 = c2[1];
            if (x2> x1 && y2>y1){
                string key1 = getKey(x1, y2);
                string key2 = getKey(x2,y1);

                if(temp.find(key1) != temp.end() and  temp.find(key2) != temp.end()){
                    count ++;
                }
            }
        }
    }
    return count;

}

int main(){
    vector<vector<int>> coord = {{0,0}, {0,1}, {1,1}, {1,0}, {2,1}, {2,0}, {3,1}, {3,0}};
    int count = rectangleCount(coord);
    cout << count;
}