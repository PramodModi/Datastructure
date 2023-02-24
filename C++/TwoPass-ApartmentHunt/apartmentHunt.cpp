/*
You're looking to move into a new apartment on specific street, 
and you're given a list of contiguous blocks on that street where each block 
contains an apartment that you could move into. You also have a list of 
requirements: a list of buildings that are important to you. For instance, 
you might value having a school and a gym near your apartment. 
The list of blocks that you have contains information at every block about all of 
the buildings that are present and absent at the block in question. 
For instance, for every block, you might know whether a school, a pool, an office, 
and a gym are present. In order to optimize your life, you want to pick an 
apartment block such that you minimize the farthest distance you'd have to walk 
from your apartment to reach any of your required buildings. 
Write a function that takes in a list of contiguous blocks on a specific street 
and a list of your required buildings and that returns the location (the index) 
of the block that's most optimal for you. If there are multiple most optimal 
blocks, your function can return the index of any one of them.

Example:
For this example, 3rd apartment has gym at distance 1, school = 0 and store = 1
blocks = [ { "gym": False, "school": True, "store": False }, 
            { "gym": True, "school": False, "store": False }, 
            { "gym": True, "school": True, "store": False }, 
            { "gym": False, "school": True, "store": False }, 
            { "gym": False, "school": True, "store": True } ]
req = ["gym", "school", "store"]

output: 3

Approach:
## This is the two pass problem. Here we will have to take care for 
all requirements.
## First create the value for each requirement from 1st block. 
## If first block does not have req, then set value = inf otherwise 0.
## Now run for all block from 2nd block to last block. If block has req, 
then set value = 0 otherwise, look at the prev value and increment by 1.

## 2nd pass start from second last, if block has req, then set value = 0, 
otherwise take minimum of value which is already calculated and earlier one.

*/

# include <iostream>
#include<vector>
#include <unordered_map>
#include<string>

using namespace std;

int getMaxValue(unordered_map<string, int> map){
    int maxVal = -1;
    for(auto [key, val] : map){
        maxVal = max(maxVal, val);
    }
    return maxVal;
}


int getApartment(vector<unordered_map<string, int>> blocks, vector<string> req){
    vector<unordered_map<string, int>> dist;
    unordered_map<string, int> firstBlock = blocks[0];
    unordered_map<string, int> tempDist;

    for(auto r : req){
        if(firstBlock[r]){
            tempDist[r] = 0;
        }
        else{
            tempDist[r] = INT_MAX;
        }
    }
    dist.push_back(tempDist);

    for(int i =1; i<blocks.size(); i++){
        unordered_map<string, int> temp;
        for(auto r : req){
            if(blocks[i][r]){
                temp[r] = 0;
            }
            else{
    //INT_MAX + 1 gives negative value. So, to avoid that below check is needed
                if(dist[i-1][r] == INT_MAX) 
                    temp[r] = dist[i-1][r];
                else
                    temp[r] = dist[i-1][r] + 1;
            }
        }
        dist.push_back(temp);
    }

    for(int i =blocks.size()-2;i>= 0; i--){
        unordered_map<string, int> temp;
        for(auto r : req){
            if(blocks[i][r]){
                temp[r] = 0;
            }
            else{
    //INT_MAX + 1 gives negative value. So, to avoid that below check is needed
                int tempDist = dist[i+1][r];
                if(tempDist != INT_MAX)
                    tempDist ++;
                temp[r] = min(tempDist, dist[i][r]);
            }
        }
        dist[i] = temp;
    }
    
    int rightApartment;
    int minDistReq = INT_MAX;
    for(int i =0; i< dist.size(); i++){
        int maxDistReqs = getMaxValue(dist[i]);
        if(minDistReq >maxDistReqs){
            minDistReq = maxDistReqs;
            rightApartment = i;
        }
    }
    return rightApartment;
}

int main(){
    vector<unordered_map<string, int>> blocks{
            { {"gym", false}, {"school", true}, {"store", false} }, 
            {{"gym", true}, {"school",false}, {"store", false} }, 
            { {"gym", true}, {"school",true}, {"store",false} }, 
            { {"gym",false}, {"school",true}, {"store", false} }, 
            { {"gym",false}, {"school",true}, {"store", true} } 
        };
    vector<string> req {"gym", "school", "store"};
    cout<<getApartment(blocks, req);

    return 1;
}


