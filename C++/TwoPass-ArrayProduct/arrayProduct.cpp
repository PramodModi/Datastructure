/*
Write a function that takes in a non-empty array of integers and returns an array 
of the same length, where each element in the output array is equal to the 
product of every other number in the input array. In other words, the value at 
output[i] is equal to the product of every number in the input array other than 
input[i] . Note that you're expected to solve this problem without using division.

Example:
array = [5, 1, 4, 2]
Output: [8, 40, 10, 20]

Approach:
Do the left multiplication. Starting from left and do the multiplication of all 
elements leaving leftmost element as 1. leftmultiplyarray = [1,5,5,20] 
similarly do it for right elements, starting from right most. 
rightmultiplyarray = [8,8,2,1] Now, multiply both array. 
Multiply elements at the same position in both arrays. 
Product = [1x8, 5x8, 5x2, 20,1] = [8,40,10,20]
Last multiplication can be done in line with second loop.
This is exactly done in the code.
*/

# include <iostream>
#include<vector>
using namespace std;

vector<int> arrayProduct(vector<int> array){
    
    vector<int> result;
    int left = 1;
    for(int num : array){
        result.push_back(left);
        left = left*num;
    }
    int right =1;
    for(int i = array.size() -1; i>=0;i--){
        result[i] *= right;
        right = right * array[i];
    }

    return result;
}

int main(){
    vector<int> array = {5, 1, 4, 2};
    vector<int> result = arrayProduct(array);
    for(int num:result){
        cout<<num<<" ";
    }
    return 1;
}