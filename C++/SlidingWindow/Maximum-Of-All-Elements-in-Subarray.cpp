vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        for(int right = 0; right<k; right ++){
            while(!dq.empty() && nums[right] > nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(right);
        }
        
        vector<int> result;
        result.push_back(nums[dq.front()]);
        int right = k;
        int left = 0;
        
        while(right < nums.size()){
            if (left == dq.front()){
                dq.pop_front();
            }
            while(!dq.empty() && nums[right] > nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(right);
            
            result.push_back(nums[dq.front()]);
            left += 1;
            right += 1;
                
            
        }
            
     return result;   
    }