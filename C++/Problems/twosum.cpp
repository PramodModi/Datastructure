# include<iostream>
# include<vector>
# include<unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> temp;
    for (auto i = 0; i< nums.size(); i++){
        int second = target - nums[i];
        if (temp.find(second) != end(temp)){
            return {temp[second], i};
        }
        else
            temp[nums[i]] = i;
    }
    return {};
        
}

int main(){

    int target = 9;
    vector<int> nums = {2,7,11,15};
    vector<int> result = twoSum(nums, target);
    
    for (auto num : result){
        cout<<num<<" ";
    }

    return 1;
}