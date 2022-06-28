string minWindow(string s, string t) {
        if (t.size() > s.size())
            return "";
        unordered_map<char, int> temp;
        
        for(auto c : t)
        {
            if (temp.find(c) != temp.end())
                temp[c] ++;
            else
                temp[c] = 1;
        }
        
        int totalChar = temp.size();
        int r = 0, l = 0, result = INT_MAX, result_lIdx = 0;
        
        while (r < s.size()){
            char c = s[r];
            if (temp.find(c) != temp.end()){
                temp[c] --;
                if (temp[c] == 0)
                    totalChar --;
            }
            while(totalChar == 0){
                char c = s[l];
                if(temp.find(c) != temp.end()){
                    temp[c] ++;
                    if (temp[c] == 1)
                        totalChar ++;
                }
                if (result > (r-l + 1)){
                    result = r-l+1;
                    result_lIdx = l;
                }
                l++;
            }
            r++;
            
        }
        return result == INT_MAX ? "" : s.substr(result_lIdx, result);
    }