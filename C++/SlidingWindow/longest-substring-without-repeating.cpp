int lengthOfLongestSubstring(string s) {
        if (s.size() == 0)
            return 0;
        int r = 0, l =0, result = 0;
        unordered_map<char, int> temp;
        while(r<s.size()){
            char c = s[r];
            if(temp.find(c) != temp.end())
                temp[c]++;
            else
                temp[c] = 1;
            
            while(r-l+1 > temp.size() && l<= r){
                c = s[l];
                if (temp.find(c) != temp.end())
                {
                    temp[c]--;
                    if(temp[c] == 0)
                        temp.erase(c);
                }
                l++;
                
            }
            int length = r-l+1;
            if(length == temp.size()){
                if (length > result)
                    result = length;
            }
          r++;  
        }
        return result;    
    }